/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:57:38 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/26 18:15:08 by lrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long		castor(unsigned short *map)
{
	unsigned long caster;

	caster = 0;
	caster |= (unsigned long)map[0] << (48 - 16 * 0);
	caster |= (unsigned long)map[1] << (48 - 16 * 1);
	caster |= (unsigned long)map[2] << (48 - 16 * 2);
	caster |= (unsigned long)map[3] << (48 - 16 * 3);
	return (caster);
}

void				uncastor(unsigned long caster, unsigned short *map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[i] = (unsigned short)(caster >> (48 - 16 * i));
		i++;
	}
}

void				placer(t_tetri *piece, unsigned short *map)
{
	uncastor(castor(map) | piece->value, map);
}

t_bool				update_coord(t_tetri *piece, int i, int j)
{
	piece->y = i;
	piece->x = j;
	return (TRUE);
}

t_bool				backtracking(t_tetri **pieces, int tetri, int *carre,
		unsigned short *map)
{
	int		i;
	int		j;

	j = -1;
	i = -1;
	while (++i + pieces[tetri]->height <= *carre)
	{
		while (++j + pieces[tetri]->length <= *carre)
		{
			if ((!(pieces[tetri]->value & castor(map + i))))
			{
				placer(pieces[tetri], map + i);
				if ((!pieces[tetri + 1] || backtracking(pieces, tetri + 1,
							carre, map)) && update_coord(pieces[tetri], i , j))
					return (TRUE);
				uncastor(castor(map + i) ^ (pieces[tetri]->value), map + i);
			}
			pieces[tetri]->value >>= 1;
		}
		pieces[tetri]->value <<= j;
		j = -1;
	}
	return (FALSE);
}
