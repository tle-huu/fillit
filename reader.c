/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:07:18 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/25 18:03:10 by lrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*read_input(int fd)
{
	int			reader;
	char		buf[547];
	char		*str;

	reader = read(fd, buf, 546);
	if (reader > 545)
		return (NULL);
	buf[reader] = '\0';
	if (!(str = ft_strnew(ft_strlen(buf))))
		exit(1);
	ft_strncpy(str, (const char *)buf, reader + 1);
	return (str);
}

static void		check_input(char *str)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	if (!str)
		print_error();
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			print_error();
		if (str[i] == '#')
			count++;
		i++;
	}
	if (!count)
		print_error();
}

static char		*ft_copy(char *src, size_t n)
{
	size_t		i;
	size_t		j;
	char		*dest;

	i = 0;
	j = 0;
	if (!(dest = ft_strnew(16)))
		exit(1);
	while (src[i] && i < n)
	{
		if (src[i] != '\n')
		{
			dest[j] = src[i];
			j++;
		}
		i++;
	}
	if (ft_strlen(dest) != 16)
		print_error();
	return (dest);
}

static void		fill_struct(t_tetri **pieces, int j)
{
	while (j < 28)
	{
		pieces[j] = NULL;
		j++;
	}
}

t_tetri			**create_struct(char *s)
{
	int					i;
	int					j;
	t_tetri				**tab;

	j = 0;
	i = 0;
	check_input(s);
	if (!(tab = (t_tetri**)malloc(sizeof(t_tetri*) * (27))))
		return (NULL);
	while (s[i])
	{
		if (s[i])
		{
			i += s[i] == '\n' ? 1 : 0;
			tab[j] = turn_into(ft_copy(s + i, 20), 0);
			i += 20;
			if (s[i] && s[i] != '\n')
				print_error();
			j++;
		}
	}
	fill_struct(tab, j);
	return (tab);
}
