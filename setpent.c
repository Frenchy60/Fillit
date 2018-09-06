/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 02:56:07 by agraton           #+#    #+#             */
/*   Updated: 2018/07/27 17:21:47 by fverhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pent.h"

t_pent			*createpentelem(char **pent, t_pent *next)
{
	t_pent		*new;

	if (!(new = (t_pent*)malloc(sizeof(t_pent))))
		return (NULL);
	new->pent = pent;
	new->next = next;
	return (new);
}

void			movepentup(char **pent)
{
	int			i;
	int			j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 4)
			pent[i][j] = pent[i + 1][j];
	}
	j = -1;
	while (++j < 4)
		pent[3][j] = '.';
}

void			movepentleft(char **pent)
{
	int			i;
	int			j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 4)
			pent[j][i] = pent[j][i + 1];
	}
	j = -1;
	while (++j < 4)
		pent[j][3] = '.';
}

void			fixpentlist(t_pent *list)
{
	int			flag;

	if (!list)
		return ;
	flag = 1;
	while (list && list->pent[0][0] == '.' && flag == 1)
	{
		if (list->pent[0][1] == '.' && list->pent[0][2] == '.' &&
				list->pent[0][3] == '.')
		{
			movepentup(list->pent);
		}
		else if (list->pent[1][0] == '.' && list->pent[2][0] == '.' &&
				list->pent[3][0] == '.')
		{
			movepentleft(list->pent);
		}
		else
			flag = 0;
	}
	fixpentlist(list->next);
}

void			reverse(t_pent **begin_list)
{
	t_pent		*prev;
	t_pent		*cur;
	t_pent		*next;

	if (!(*begin_list))
		return ;
	if (!((*begin_list)->next))
		return ;
	prev = *begin_list;
	cur = prev->next;
	next = cur->next;
	prev->next = 0;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*begin_list = prev;
}
