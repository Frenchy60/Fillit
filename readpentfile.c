/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readpentfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 04:59:23 by agraton           #+#    #+#             */
/*   Updated: 2018/09/06 17:03:17 by fverhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pent.h"

char		**newar(int x, int y, char c)
{
	char	**ar;
	int		i;
	int		j;

	ar = (char**)malloc(sizeof(char*) * x);
	i = -1;
	while (++i < x)
		ar[i] = (char*)malloc(sizeof(char) * y);
	i = -1;
	while (-1 == (j = -1) && ++i < x)
		while (++j < y)
			ar[i][j] = c;
	return (ar);
}

t_pent		*readvalidfile(int fd)
{
	char	c;
	char	**ar;
	int		i;
	int		j;
	t_pent	*list;

	list = NULL;
	c = '\n';
	while (c)
	{
		ar = newar(4, 4, '.');
		i = -1;
		while (-1 == (j = -1) && ++i < 4)
		{
			while (++j < 4)
				read(fd, &(ar[i][j]), 1);
			read(fd, &c, 1);
		}
		if (!(read(fd, &c, 1)))
			c = '\0';
		list = createpentelem(ar, list);
	}
	return (list);
}

void		printlist(t_pent *list)
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
		{
			write(1, &(list->pent[i][j]), 1);
		}
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
	printlist(list->next);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_pent	*list;

	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (-1);
	}
	if (-1 == (fd = open(argv[1], O_RDONLY)) || 0 != checkfile(fd))
	{
		write(1, "error\n", 6);
		return (-1);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	list = readvalidfile(fd);
	fixpentlist(list);
	reverse(&list);
	giveletters(list, 'A');
	startsearch(list);
	list_delete(&list);
	return (0);
}
