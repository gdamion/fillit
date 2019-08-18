/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:31:02 by gdamion-          #+#    #+#             */
/*   Updated: 2019/08/18 18:18:46 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		processing(char ***tetros, int (*c)[3])
{
	char	**res;
	int		**pos;
	int		a;

	if (!(res_alloc(&res, (*c)[0])))
		error(tetros, 0);
	if (!(pos_alloc(&pos, (*c)[1])))
	{
		res_clean(res, (*c)[0]);
		error(tetros, 0);
	}
	while (1)
	{
		a = try_to_assemble(res, tetros, &pos, c);
		if (a == 0)
		{
			res_clean(res, (*c)[0]);
			pos_clean(pos, (*c)[1]);
			return (0);
		}
		else if (a == 1)
			continue;
		print_res(res);
		exit(1);
	}
}

int		pos_alloc(int ***pos, int fcnt)
{
	int i;

	if (!(*pos = (int**)malloc(sizeof(int*) * (fcnt + 1))))
		return (0);
	i = 0;
	while (i < fcnt)
	{
		if (!((*pos)[i] = (int*)malloc(sizeof(int) * 2)))
		{
			pos_clean(*pos, i);
			return (0);
		}
		ft_bzero((*pos)[i], sizeof(int) * 2);
		i++;
	}
	(*pos)[fcnt] = NULL;
	return (1);
}

int		res_alloc(char ***res, int msize)
{
	int i;
	int j;

	if (!(*res = (char**)malloc(sizeof(char*) * (msize + 1))))
		return (0);
	i = 0;
	while (i < msize)
	{
		if (!((*res)[i] = (char*)malloc(sizeof(char) * (msize + 1))))
		{
			res_clean(*res, i);
			return (0);
		}
		j = 0;
		while (j < msize)
		{
			(*res)[i][j] = '.';
			j++;
		}
		(*res)[i][j] = '\0';
		i++;
	}
	(*res)[msize] = NULL;
	return (1);
}

void	pos_clean(int **pos, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(pos[i]);
		i++;
	}
	free(pos);
}

void	res_clean(char **res, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(res[i]);
		i++;
	}
	free(res);
}
