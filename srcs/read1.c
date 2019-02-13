/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:27:45 by gdamion-          #+#    #+#             */
/*   Updated: 2019/02/13 18:28:51 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	***tetros;
	int		msize;
	int		fnum;

	fnum = 0;
	tetros = (char***)malloc(sizeof(char***) * (26 + 1));
	ft_bzero(tetros, sizeof(char***) * 27);
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(0);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		error(tetros, 0);
		exit(0);
	}
	input(tetros, &fnum, fd);
	msize = sqrt_spec(fnum);
	while (!(processing(tetros, msize, fnum + 1)))
		msize++;
	error(tetros, 1);
	return (0);
}

int		sqrt_spec(int fnum)
{
	int	i;

	i = 2;
	while ((i * i) < (fnum * 4))
		i++;
	return (i);
}

int		input(char ***tetros, int *fnum, int fd)
{
	int		rd;
	char	buf[22];

	if (!(*fnum < 26))
		error(tetros, 0);
	ft_bzero(buf, 22);
	rd = read(fd, buf, 21);
	if (rd < 20)
		error(tetros, 0);
	tetro_validity(buf, tetros);
	add_tetro_into_arr(tetros, buf, *fnum);
	standart_pose(tetros, *fnum);
	if (rd == 21)
	{
		*fnum += 1;
		input(tetros, fnum, fd);
		return (1);
	}
	if (rd != 20)
		error(tetros, 0);
	return (0);
}

void	tetro_validity(char *t, char ***tetros)
{
	int c[5];

	ft_bzero((void*)c, 5 * sizeof(int));
	while (c[0] != 20)
	{
		if (t[c[0]] != '#' && t[c[0]] != '.' && t[c[0]] != '\n')
			error(tetros, 0);
		if (t[c[0]] == '\n')
		{
			c[3]++;
			if (c[2] != 4)
				error(tetros, 0);
			c[2] = 0;
		}
		else
			c[2]++;
		if (t[c[0]] == '#')
			c[4] = add_connections(c[0], &(c[1]), c[4], t);
		c[0]++;
	}
	if ((t[c[0]] != '\n' && t[c[0]] != '\0')
		|| (c[1] != 4 && c[1] != 0)
		|| c[3] != 4 || c[4] < 6)
		error(tetros, 0);
}

int		add_connections(int n, int *occur, int con, char *t)
{
	if ((n - 5) >= 0 && (n - 5) < 19 && t[n - 5] == '#')
		con++;
	if ((n - 1) >= 0 && (n - 1) < 19 && t[n - 1] == '#')
		con++;
	if ((n + 5) >= 0 && (n + 5) < 19 && t[n + 5] == '#')
		con++;
	if ((n + 1) >= 0 && (n + 1) < 19 && t[n + 1] == '#')
		con++;
	(*occur)++;
	return (con);
}
