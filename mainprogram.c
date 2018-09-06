/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainprogram.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:12:55 by agraton           #+#    #+#             */
/*   Updated: 2018/09/06 17:04:42 by fverhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pent.h"

void		removetet(char **ar, char **board, int size)
{
	char	c;
	int		i;
	int		j;

	c = '.';
	i = -1;
	while (-1 == (j = -1) && ++i < 4)
		while (++j < 4)
			if (ar[i][j] != '.')
				c = ar[i][j];
	i = -1;
	while (-1 == (j = -1) && ++i < size)
		while (++j < size)
			if (board[i][j] == c)
				board[i][j] = '.';
}

int			addtet(char **ar, char **board, int dim[2], int size)
{
	int		i;
	int		j;

	i = -1;
	while (-1 == (j = -1) && ++i < 4)
		while (++j < 4)
			if (((dim[0] + j >= size || dim[1] + i >= size) && ar[i][j] != '.')
					|| (ar[i][j] != '.' &&
						(board[dim[1] + i][dim[0] + j] != '.')))
				return (0);
	i = -1;
	while (-1 == (j = -1) && ++i < 4)
		while (++j < 4)
			if (ar[i][j] != '.')
				board[dim[1] + i][dim[0] + j] = ar[i][j];
	return (1);
}

int			printsolution(char **board, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			write(1, &board[i][j], 1);
		write(1, "\n", 1);
	}
	return (0);
}

int			trysize(t_pent *list, int size, char **board)
{
	int		pos[2];

	if (!list)
	{
		return (printsolution(board, size));
	}
	pos[1] = -1;
	while (-1 == (pos[0] = -1) && ++pos[1] < size)
		while (++pos[0] < size)
		{
			if (addtet(list->pent, board, pos, size))
			{
				if (trysize(list->next, size, board) == 0)
					return (0);
				removetet(list->pent, board, size);
			}
		}
	return (1);
}

void		startsearch(t_pent *list)
{
	int		i;
	char	**board;
	int		flag;

	flag = 1;
	i = 2;
	while (i * i < getlistsize(list) * 4)
		i++;
	while (flag)
	{
		board = newar(i, i, '.');
		flag = trysize(list, i, board);
		free_double_char_array(board, i);
		i++;
	}
}
