#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 16:40:55 by aryabenk          #+#    #+#              #
#    Updated: 2018/03/13 16:40:56 by aryabenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

SRC = ./ft_lem_in/ft_add_parameters.c ./ft_lem_in/ft_check.c \
      ./ft_lem_in/ft_create_lst.c ./ft_lem_in/ft_distance.c \
      ./ft_lem_in/ft_error.c ./ft_lem_in/ft_links_matrix.c \
      ./ft_lem_in/ft_lst_del.c ./ft_lem_in/ft_move_ants.c \
      ./ft_lem_in/ft_read_args.c ./ft_lem_in/ft_set_ants.c \
      ./ft_lem_in/ft_sort_ants.c ./ft_lem_in/ft_sort_ways.c \
      ./ft_lem_in/ft_ways.c ./ft_lem_in/main.c ./ft_lem_in/ft_check_room.c \
      ./ft_lem_in/ft_find_flags.c ./ft_lem_in/ft_bonus.c \
      ./ft_lem_in/ft_print_ants.c ./ft_lem_in/ft_find_ants.c

MLIB = make -C libftprintf

LIB = libftprintf/libftprintf.a

all: $(NAME)

$(NAME): $(SRC)
	$(MLIB)
	gcc -Wall -Wextra -Werror $(SRC) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MLIB) clean

fclean: clean
	rm -f $(NAME)
	$(MLIB) fclean

re: fclean all