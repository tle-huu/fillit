/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:28:49 by lrobert           #+#    #+#             */
/*   Updated: 2017/11/25 16:35:21 by lrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**init_final_map(short int carre)
{
	char			**tab;
	short	int		i;
	short	int		j;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * carre + 1)))
		return (NULL);
	while (i < carre)
	{
		tab[i] = ft_strnew(carre);
		i++;
	}
	i = 0;
	while (i < carre)
	{
		j = 0;
		while (j < carre)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	tab[carre] = NULL;
	return (tab);
}

void	place_letters(t_tetri *pieces, int carre, char **f, char c)
{
	short int				i;
	short int				j;
	short int				x;
	short int				y;
	unsigned	long		mask;

	i = 0;
	j = 0;
	y = pieces->x;
	x = pieces->y;
	mask = 0x8000000000000000 >> pieces->x;
	while (x + i < carre && i < 4)
	{
		j = 0;
		while (y + j < carre && j < 4)
		{
			if (pieces->value & mask)
				f[x + i][y + j] = c;
			j++;
			mask >>= 1;
		}
		mask = mask << j;
		mask = mask >> 16;
		i++;
	}
}

char	**letters_map(t_tetri **pieces, short int carre)
{
	char	**final_tab;
	int		i;
	char	letters;

	i = 0;
	letters = 65;
	final_tab = init_final_map(carre);
	while (pieces[i])
	{
		place_letters(pieces[i], carre, final_tab, letters);
		i++;
		letters++;
	}
	return (final_tab);
}

void	print_map(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putendl((char *)s[i]);
		i++;
	}
}
