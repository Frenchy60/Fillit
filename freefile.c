/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fverhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 16:47:47 by fverhuls          #+#    #+#             */
/*   Updated: 2018/09/06 17:09:45 by fverhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pent.h"

void		free_double_char_array(char **arr, int a)
{
	int		i;

	i = -1;
	while (++i < a)
	{
		free(arr[i]);
	}
	free(arr);
}

void		list_delete(t_pent **alst)
{
	t_pent	*lst;
	t_pent	*nxtlst;

	lst = *alst;
	while (lst)
	{
		nxtlst = lst->next;
		free_double_char_array(lst->pent, 4);
		free(lst);
		lst = nxtlst;
	}
	*alst = NULL;
}
