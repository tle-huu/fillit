/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 07:53:47 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/25 18:02:45 by lrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char		tetri_height(unsigned long value)
{
	unsigned	long	mask;
	char				height;
	char				i;

	i = 0;
	height = 0;
	mask = 0xF000000000000000;
	while (i < 4)
	{
		height += mask & value ? 1 : 0;
		mask = mask >> 16;
		i++;
	}
	return (height);
}

static	char		tetri_length(unsigned long value)
{
	unsigned	long	mask;
	char				length;
	char				i;

	i = 0;
	length = 0;
	mask = 0x8000800080008000;
	while (i < 4)
	{
		length += (mask & value) ? 1 : 0;
		mask = mask >> 1;
		i++;
	}
	return (length);
}

static	t_tetri		*new_tetri(unsigned long value, char length, char height)
{
	t_tetri		*tetriminos;

	if (!(tetriminos = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	tetriminos->value = value;
	tetriminos->length = length;
	tetriminos->height = height;
	tetriminos->x = 0;
	tetriminos->y = 0;
	return (tetriminos);
}

t_tetri				*turn_into(char *str, int count)
{
	unsigned	long	value;
	unsigned	char	i;
	unsigned	long	mask;

	i = 0;
	mask = 0x8000800080008000;
	value = 0;
	while (str[i])
	{
		count += str[i] == '#' ? 1 : 0;
		if (str[i] == '#')
			value |= ((unsigned long)1 << (16 * (4 - i / 4) - (i % 4) - 1));
		i++;
	}
	if (!count)
		print_error();
	while ((mask & value) == 0)
		value <<= 1;
	mask = 0xF000000000000000;
	while ((mask & value) == 0)
		value <<= 16;
	return (new_tetri(value, tetri_length(value), tetri_height(value)));
}
