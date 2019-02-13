/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:42:54 by pcollio-          #+#    #+#             */
/*   Updated: 2019/02/13 18:27:06 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../lib/libft.h"

int		main(int argc, char **argv);
int		sqrt_spec(int fnum);
int		input(char ***tetros, int *fnum, int fd);
void	tetro_validity(char *t, char ***tetros);
int		add_connections(int n, int *occur, int con, char *t);

void	add_tetro_into_arr(char ***tetros, char *buf, int fnum);
void	add_tetro_into_arr2(char ***tetros, char *buf, int fnum);
void	standart_pose(char ***tetros, int fnum);
void	standart_pose2(char ***tetros, int fnum);
void	error(char ***tetros, int a);

int		processing(char ***tetros, int msize, int fcnt);
int		pos_alloc(int ***pos, int fcnt);
int		res_alloc(char ***res, int msize);
void	pos_clean(int **pos, int n);
void	res_clean(char **res, int n);

int		try_to_assemble(char **res, char ***tetros, int **pos, int c[3]);
int		add_if_possible(char **res, char **tetro, int *pos, int msize);
int		add_if_possible2(char **res, char **tetro, int *pos, int (*b)[4]);
int		add_if_possible3(char **res, char **tetro, int *pos, int (*b)[4]);

void	tetro_add(char **res, char **tetro, int *pos);
void	tetro_del(char **res, char **tetro, int *pos);
void	print_res(char **res);

#endif
