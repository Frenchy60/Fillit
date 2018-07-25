/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pent.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 02:48:58 by agraton           #+#    #+#             */
/*   Updated: 2018/07/16 14:21:02 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PENT_H
# define T_PENT_H

# include <string.h>

typedef struct		s_pent
{
	char			**pent;
	struct s_pent	*next;
}					t_pent;

#endif
