/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:31:23 by gdamion-          #+#    #+#             */
/*   Updated: 2019/08/18 18:18:46 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetro_add(char **res, char **tetro, int **pos)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetro[i][j] != '.')
				res[(*pos)[0] + i][(*pos)[1] + j] = tetro[i][j];
			j++;
		}
		i++;
	}
}

void	tetro_del(char **res, char **tetro, int **pos)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetro[i][j] != '.')
			{
				res[(*pos)[0] + i][(*pos)[1] + j] = '.';
			}
			j++;
		}
		i++;
	}
}

void	print_res(char **res)
{
	int i;

	i = 0;
	while (res[i] != NULL)
	{
		ft_putendl(res[i]);
		i++;
	}
}
