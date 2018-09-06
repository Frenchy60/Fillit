/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pent.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 02:48:58 by agraton           #+#    #+#             */
/*   Updated: 2018/07/25 19:12:42 by fverhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PENT_H
# define T_PENT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_pent
{
	char				**pent;
	struct s_pent		*next;
}						t_pent;

int						checkpiece(char *str);
int						checklinks(char *str);
int						getlistsize(t_pent *list);
char					**newar(int x, int y, char c);
int						getscore(char **board, int size);
t_pent					*createpentelem(char **pent, t_pent *next);
void					fixpentlist(t_pent *list);
void					reverse(t_pent **begin_list);
void					giveletters(t_pent *list, char c);
void					startsearch(t_pent *list);
int						checkfile(int fd);

#endif
