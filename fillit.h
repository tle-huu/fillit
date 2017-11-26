/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:13:01 by lrobert           #+#    #+#             */
/*   Updated: 2017/11/26 18:15:19 by lrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_tetri
{
	unsigned long	value;
	char			length;
	char			height;
	char			x;
	char			y;
}						t_tetri;

typedef enum			e_bool
{
	FALSE,
	TRUE
}						t_bool;

void					affiche_tetri(t_tetri *tet);

t_tetri					*turn_into(char *str, int count);

t_tetri					**create_struct(char *s);

char					*read_input(int fd);

t_bool					backtracking(t_tetri **piece, int index, int *carre,
		unsigned short *map);

char					**letters_map(t_tetri **pieces, short int carre);

void					print_map(char **s);

t_bool					check_tetri(t_tetri **pieces);

unsigned long			castor(unsigned short *map);

t_bool					is_valid(t_tetri *piece, unsigned short *map);

int						ft_sqrt(int nb);

int						nb_pieces(t_tetri **pieces);

void					print_bits(unsigned long value);

void					print_bits_short(unsigned short value);

void					check_struct(t_tetri **pieces);
void					print_error();
#endif
