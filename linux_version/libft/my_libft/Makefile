# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atemfack <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 16:30:05 by atemfack          #+#    #+#              #
#*   Updated: 2020/04/24 22:12:50 by atemfack         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = My_libft.a 

SRC = src/ft_swap.c src/ft_max.c \
	src/ft_strrevs.c src/ft_sort_selection.c \
	src/ft_sort_rselection.c src/ft_sort_bubble.c src/ft_sort_rbubble.c \
	src/ft_sort_insertion.c src/ft_sort_rinsertion.c

OBJ = $(subst .c,.o,$(SRC))

HEADER = include

GW = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	$(GW) -I $(HEADER) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all

f:	all clean

.PHONY: all clean fclean re f
