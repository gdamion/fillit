/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:31:19 by gdamion-          #+#    #+#             */
/*   Updated: 2019/02/15 19:37:54 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		try_to_assemble(char **res, char ***tetros, int ***pos, int (*c)[3])
{
	if ((*c)[2] == (*c)[1])
		return (2);
	if (!(add_if_possible(res, tetros[(*c)[2]], &((*pos)[(*c)[2]]), (*c)[0])))
	{
		if ((*c)[2] == 0)
			return (0);
		(*pos)[(*c)[2]][0] = 0;
		(*pos)[(*c)[2]][1] = 0;
		(*c)[2]--;
		tetro_del(res, tetros[(*c)[2]], &((*pos)[(*c)[2]]));
		(*pos)[(*c)[2]][1]++;
		if ((*pos)[(*c)[2]][1] == (*c)[0])
		{
			(*pos)[(*c)[2]][1] = 0;
			(*pos)[(*c)[2]][0]++;
		}
		return (1);
	}
	(*c)[2]++;
	return (1);
}

int		add_if_possible(char **res, char **tetro, int **pos, int msize)
{
	int b[4];

	b[0] = msize;
	b[1] = 0;
	while ((*pos)[0] < b[0])
	{
		while ((*pos)[1] < b[0])
		{
			if (add_if_possible2(res, tetro, pos, &b))
				return (1);
		}
		(*pos)[1] = 0;
		(*pos)[0]++;
	}
	return (0);
}

int		add_if_possible2(char **res, char **tetro, int **pos, int (*b)[4])
{
	(*b)[2] = 0;
	while ((*b)[2] < 4)
	{
		(*b)[3] = 0;
		while ((*b)[3] < 4)
		{
			if (!(add_if_possible3(res, tetro, pos, b)))
				break ;
			if ((*b)[1] == 4)
			{
				tetro_add(res, tetro, pos);
				return (1);
			}
			(*b)[3]++;
		}
		(*b)[2]++;
	}
	(*b)[1] = 0;
	(*pos)[1]++;
	return (0);
}

int		add_if_possible3(char **res, char **tetro, int **pos, int (*b)[4])
{
	if (tetro[(*b)[2]][(*b)[3]] != '.')
	{
		if (((*pos)[0] + (*b)[2]) < (*b)[0] && ((*pos)[1] + (*b)[3]) < (*b)[0])
		{
			if (res[(*pos)[0] + (*b)[2]][(*pos)[1] + (*b)[3]] == '.')
				(*b)[1]++;
			else
			{
				(*b)[2] = 3;
				return (0);
			}
		}
		else
		{
			(*b)[2] = 3;
			return (0);
		}
	}
	return (1);
}
