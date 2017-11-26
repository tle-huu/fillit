/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 13:33:15 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/25 16:22:02 by lrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int		i;

	i = 0;
	if (nb == 2)
		return (1);
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i - 1);
}

int		nb_pieces(t_tetri **pieces)
{
	int		i;

	i = 0;
	while (pieces[i])
		i++;
	return (i);
}

void	print_error(void)
{
	ft_putendl("error");
	exit(1);
}
