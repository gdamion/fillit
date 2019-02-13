/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:28:07 by gdamion-          #+#    #+#             */
/*   Updated: 2019/02/13 18:29:44 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_tetro_into_arr(char ***tetros, char *buf, int fnum)
{
	int i;

	if (!(tetros[fnum] = (char**)malloc(sizeof(char**) * (4 + 1))))
		error(tetros, 0);
	ft_bzero(tetros[fnum], 5);
	i = 0;
	while (i < 4)
	{
		if (!(tetros[fnum][i] = (char*)malloc(sizeof(char*) * (4 + 1))))
			error(tetros, 0);
		ft_bzero(tetros[fnum][i], 5);
		i++;
	}
	add_tetro_into_arr2(tetros, buf, fnum);
}

void	add_tetro_into_arr2(char ***tetros, char *buf, int fnum)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (*buf == '#')
				tetros[fnum][i][j] = (char)(fnum + 65);
			else
				tetros[fnum][i][j] = '.';
			j++;
			buf++;
		}
		buf++;
		i++;
	}
}

void	standart_pose(char ***tetros, int fnum)
{
	int		j;
	char	*temp;

	while (1)
	{
		j = 0;
		while (j < 4)
		{
			if (tetros[fnum][0][j] != '.')
				break ;
			j++;
		}
		if (j == 4)
		{
			temp = tetros[fnum][0];
			tetros[fnum][0] = tetros[fnum][1];
			tetros[fnum][1] = tetros[fnum][2];
			tetros[fnum][2] = tetros[fnum][3];
			tetros[fnum][3] = temp;
		}
		else
			break ;
	}
	standart_pose2(tetros, fnum);
}

void	standart_pose2(char ***tetros, int fnum)
{
	int i;

	while (1)
	{
		i = 0;
		while (i < 4)
		{
			if (tetros[fnum][i][0] != '.')
				break ;
			i++;
		}
		if (i == 4)
		{
			i = -1;
			while (++i < 4)
			{
				tetros[fnum][i][0] = tetros[fnum][i][1];
				tetros[fnum][i][1] = tetros[fnum][i][2];
				tetros[fnum][i][2] = tetros[fnum][i][3];
				tetros[fnum][i][3] = '.';
			}
		}
		else
			break ;
	}
}

void	error(char ***tetros, int a)
{
	int i;
	int j;

	i = 0;
	while (tetros[i])
	{
		j = 0;
		while (tetros[i][j])
		{
			free(tetros[i][j]);
			j++;
		}
		free(tetros[i]);
		i++;
	}
	free(tetros);
	if (!a)
	{
		ft_putendl("error");
		exit(0);
	}
}
