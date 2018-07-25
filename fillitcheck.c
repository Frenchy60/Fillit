/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fverhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 18:48:23 by fverhuls          #+#    #+#             */
/*   Updated: 2018/07/25 17:28:22 by fverhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int			checkpiece(char *str);
int			checklinks(char *str);

int			checkfile(int fd)
{
	char	*str;
	int		count;

	count = 0;
	str = malloc(sizeof(char) * 21);
	*str = '\n';
	str[20] = '\0';
	while (*str == '\n')
	{
		count++;
		if (!(read(fd, str, 20)))
		{
			return (-1);
		}
		if (checkpiece(str) != 0 || checklinks(str) != 0)
			return (-1);
		if (read(fd, str, 1) && *str != '\n')
		{
			return (-1);
		}
	}
	if (count <= 26)
		return (0);
	return (-1);
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
