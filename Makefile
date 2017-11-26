# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrobert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 15:14:25 by lrobert           #+#    #+#              #
#    Updated: 2017/11/25 16:17:52 by lrobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=fillit

FLAGS=-Wall -Wextra -Werror

SRC=main.c\
	reader.c\
	errors.c\
	tetri_process.c\
	backtracking.c\
	func.c\
	print_map.c
LIB=libft/libft.a

OBJ = $(SRC:.c=.o)

COLOR=\033[0;32m

NC=\033[0;0m

all: $(NAME)

$(NAME): $(LIB)
	gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME)
	@echo "${COLOR}Compiling fillit: done${NC}"

$(LIB):
	cd libft && make
	@echo "${COLOR}Compiling libft: done${NC}"
clean:
	cd libft && make clean
	@echo "${COLOR}Cleaning libft: done${NC}"
	rm -f $(OBJ)
	@echo "${COLOR}Cleaning current folder: done${NC}"

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)
	@echo "${COLOR}Current folder and libft executables have "\
	"been cleaned${NC}"
re: fclean all

.PHONY: all clean fclean re
