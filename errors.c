/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:03:53 by lrobert           #+#    #+#             */
/*   Updated: 2017/11/25 18:01:12 by lrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned	long	*tetri_en_dur(void)
{
	unsigned	long	*tab;

	if (!(tab = (unsigned long *)malloc(sizeof(unsigned long) * 19)))
		return (NULL);
	tab[0] = 0xF000000000000000;
	tab[1] = 0x8000800080008000;
	tab[2] = 0x80008000c0000000;
	tab[3] = 0xe000800000000000;
	tab[4] = 0xc000400040000000;
	tab[5] = 0x2000e00000000000;
	tab[6] = 0x40004000c0000000;
	tab[7] = 0x8000e00000000000;
	tab[8] = 0xc000800080000000;
	tab[9] = 0xe000200000000000;
	tab[10] = 0x6000c00000000000;
	tab[11] = 0x8000c00040000000;
	tab[12] = 0xc000600000000000;
	tab[13] = 0x4000c00080000000;
	tab[14] = 0xc000c00000000000;
	tab[15] = 0x8000c00080000000;
	tab[16] = 0xe000400000000000;
	tab[17] = 0x4000c00040000000;
	tab[18] = 0x4000e00000000000;
	return (tab);
}

t_bool				is_tetri(t_tetri *tetriminos, unsigned long *tab)
{
	short int		i;

	i = 0;
	while (i < 19)
	{
		if (tab[i] == tetriminos->value)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool				check_tetri(t_tetri **tetri)
{
	short		int			index;
	unsigned	long		*tab;

	if (!(tab = tetri_en_dur()))
		return (FALSE);
	index = 0;
	while (tetri[index] != NULL)
	{
		if (is_tetri(tetri[index], tab))
			index++;
		else
		{
			ft_putendl("error");
			exit(1);
		}
	}
	return (TRUE);
}
