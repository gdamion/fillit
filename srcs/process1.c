/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:31:02 by gdamion-          #+#    #+#             */
/*   Updated: 2019/02/13 18:36:53 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		processing(char ***tetros, int msize, int fcnt)
{
	char	**res;
	int		**pos;
	int		c[3];

	if (!(res_alloc(&res, msize)))
		error(tetros, 0);
	if (!(pos_alloc(&pos, fcnt)))
	{
		res_clean(res, msize);
		error(tetros, 0);
	}
	c[0] = msize;
	c[1] = fcnt;
	c[2] = 0;
	if (!(try_to_assemble(res, tetros, pos, c)))
	{
		res_clean(res, msize);
		pos_clean(pos, fcnt);
		return (0);
	}
	print_res(res);
	res_clean(res, msize);
	pos_clean(pos, fcnt);
	return (1);
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
