/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fverhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 18:48:23 by fverhuls          #+#    #+#             */
/*   Updated: 2018/07/25 19:09:38 by fverhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pent.h"

void		clearstr(char *str)
{
	int		i;

	i = -1;
	while (++i < 21)
		str[i] = '\0';
}

int			checkfile(int fd)
{
	char	*str;
	int		count;

	count = 0;
	str = malloc(sizeof(char) * 21);
	*str = '\n';
	str[20] = '\0';
	while (count == 0 || read(fd, str, 1))
	{
		if (*str != '\n')
			return (-1);
		clearstr(str);
		count++;
		if (!(read(fd, str, 20)))
		{
			return (-1);
		}
		if (checkpiece(str) != 0 || checklinks(str) != 0)
			return (-1);
		if (count > 26)
			return (-1);
	}
	return (0);
}

int			checkpiece(char *str)
{
	int		i;
	int		hashtag;

	i = 0;
	hashtag = 0;
	while (*str)
	{
		while (str[i] == '#' || str[i] == '.' || (i % 5 == 4 && str[i] == '\n'))
		{
			if (str[i] == '#')
				hashtag++;
			i++;
		}
		if (i == 20 && hashtag == 4)
		{
			return (0);
		}
		else
		{
			return (1);
		}
	}
	return (0);
}

int			checklinks(char *str)
{
	int		i;
	int		links;

	i = 0;
	links = 0;
	while (str[i] == '.' || str[i] == '#' || str[i] == '\n')
	{
		if (str[i] == '#')
		{
			if (str[i - 1] == '#')
				links++;
			if (str[i - 5] == '#')
				links++;
			if (str[i + 1] == '#')
				links++;
			if (str[i + 5] == '#')
				links++;
		}
		i++;
	}
	if (links >= 6)
		return (0);
	else
		return (1);
}
