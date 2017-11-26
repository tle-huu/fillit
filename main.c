/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 11:20:49 by lrobert           #+#    #+#             */
/*   Updated: 2017/11/26 18:18:41 by lrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit(char *str)
{
	int					fd;
	t_tetri				**pieces;
	unsigned short		map[16];
	int					carre;

	if ((fd = open(str, O_RDONLY)) < 0)
		return (-1);
	if (!(pieces = create_struct(read_input(fd))))
		return (-2);
	if (check_tetri(pieces) == FALSE)
		return (-2);
	carre = 2 * ft_sqrt(nb_pieces(pieces));
	ft_bzero(map, sizeof(unsigned short) * 16);
	while (!(backtracking(pieces, 0, &carre, map)))
		carre++;
	print_map(letters_map(pieces, carre));
	return (1);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if ((fillit(argv[1]) == -1))
			print_error();
	}
	else
		ft_putendl("usage: ./fillit source_file");
	return (0);
}
