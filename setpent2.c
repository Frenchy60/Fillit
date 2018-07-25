/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpent2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 10:17:31 by agraton           #+#    #+#             */
/*   Updated: 2018/07/21 12:07:53 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pent.h"

void		giveletters(t_pent *list, char c)
{
	int		i;
	int		j;

	if (!list)
		return ;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (list->pent[i][j] != '.')
				list->pent[i][j] = c;
	}
	giveletters(list->next, ++c);
}

int			getlistsize(t_pent *list)
{
	if (!list)
		return (0);
	return (getlistsize(list->next) + 1);
}

char		**getcontent(t_pent *list, int x)
{
	if (x < 1)
		return (NULL);
	if (x == 1)
		return (list->pent);
	return (getcontent(list->next, --x));
}
