# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atemfack <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 16:30:05 by atemfack          #+#    #+#              #
#*   Updated: 2020/05/19 20:56:00 by atemfack         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ../libft_42/ft_memset.c ../libft_42/ft_memmove.c ../libft_42/ft_isdigit.c \
	../libft_42/ft_strlen.c ../libft_42/ft_strcpy.c ../libft_42/ft_strchr.c \
	../libft_42/ft_atoi.c ../libft_42/ft_strdup.c ../libft_42/ft_substr.c \
	../libft_42/ft_itoa.c ../libft_42/ft_putstr_fd.c \
	ft_printf.c ft_args1.c ft_extract_fparameters2.c \
	ft_check_fparameters3.c ft_putargs4.c ft_pf_perror.c ft_specifier_c.c \
	ft_specifier_s.c ft_specifier_p.c ft_specifier_di.c ft_specifier_u.c \
	ft_specifier_xx.c ft_specifier_mod.c ft_specifier_n.c ft_specifier_f.c

OBJ1 = $(subst .c,.o,$(SRC))

OBJ = $(subst ../libft_42/ft,ft,$(OBJ1))

GW = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	$(GW) -I ../libft_42 -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

f: all clean

.PHONY: clean fclean all re bunus f
