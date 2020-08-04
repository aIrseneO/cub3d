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

NAME = libft.a 

SRC_MY_LIBFT = my_libft/src/ft_swap.c my_libft/src/ft_max.c \
	my_libft/src/ft_strrevs.c my_libft/src/ft_sort_selection.c \
	my_libft/src/ft_sort_rselection.c my_libft/src/ft_sort_bubble.c \
	my_libft/src/ft_sort_rbubble.c my_libft/src/ft_sort_insertion.c \
	my_libft/src/ft_sort_rinsertion.c

SRC_LIBFT_42 = libft_42/ft_memset.c libft_42/ft_bzero.c libft_42/ft_memcpy.c \
	libft_42/ft_memccpy.c libft_42/ft_memmove.c libft_42/ft_memchr.c \
	libft_42/ft_memcmp.c libft_42/ft_calloc.c libft_42/ft_memalloc.c \
	libft_42/ft_memdel.c libft_42/ft_strnew.c libft_42/ft_strdel.c \
	libft_42/ft_strclr.c libft_42/ft_isalpha.c libft_42/ft_isdigit.c \
	libft_42/ft_isalnum.c libft_42/ft_isascii.c libft_42/ft_isprint.c \
	libft_42/ft_toupper.c libft_42/ft_tolower.c libft_42/ft_isspace.c \
	libft_42/ft_strlen.c libft_42/ft_strcpy.c libft_42/ft_strlcpy.c \
	libft_42/ft_strcat.c libft_42/ft_strlcat.c libft_42/ft_strchr.c \
	libft_42/ft_strrchr.c libft_42/ft_strstr.c libft_42/ft_strnstr.c \
	libft_42/ft_strcmp.c libft_42/ft_strncmp.c libft_42/ft_atoi.c \
	libft_42/ft_strdup.c libft_42/ft_substr.c libft_42/ft_strjoin.c \
	libft_42/ft_strtrim.c libft_42/ft_split.c libft_42/ft_itoa.c \
	libft_42/ft_striter.c libft_42/ft_striteri.c libft_42/ft_strmap.c \
	libft_42/ft_strmapi.c libft_42/ft_putchar_fd.c libft_42/ft_putstr_fd.c \
	libft_42/ft_putendl_fd.c libft_42/ft_putnbr_fd.c libft_42/ft_lstnew.c \
	libft_42/ft_lstadd_front.c libft_42/ft_lstsize.c libft_42/ft_lstlast.c \
	libft_42/ft_lstadd_back.c libft_42/ft_lstdelone.c \
	libft_42/ft_lstdelhead.c libft_42/ft_lstclear.c libft_42/ft_lstiter.c \
	libft_42/ft_lstmap.c \
	libft_42/ft_atoi_base.c libft_42/ft_utoa_base.c  libft_42/ft_rgbcolor.c\
	libft_42/ft_isfx_ptrmove.c

SRC_FT_PRINTF = ft_printf/ft_printf.c ft_printf/ft_args1.c \
	ft_printf/ft_extract_fparameters2.c ft_printf/ft_check_fparameters3.c \
	ft_printf/ft_putargs4.c ft_printf/ft_pf_perror.c \
	ft_printf/ft_specifier_c.c ft_printf/ft_specifier_s.c \
	ft_printf/ft_specifier_p.c ft_printf/ft_specifier_di.c \
	ft_printf/ft_specifier_u.c ft_printf/ft_specifier_xx.c \
	ft_printf/ft_specifier_mod.c ft_printf/ft_specifier_n.c \
	ft_printf/ft_specifier_f.c

SRC_GET_NEXT_LINE = get_next_line/get_next_line_bonus.c \
	get_next_line/get_next_line_utils_bonus.c

SRC = $(SRC_MY_LIBFT) $(SRC_LIBFT_42) $(SRC_FT_PRINTF) $(SRC_GET_NEXT_LINE)

BUFFER_SIZE = 42

FD_SIZE = 42

HEADER_MY_LIBFT = my_libft/include

HEADER_LIBFT_42 = libft_42/

HEADER_FT_PRINTF = ft_printf/

HEADER_GET_NEXT_LINE = get_next_line/

OBJ1 = $(subst my_libft/src/ft,ft,$(SRC_MY_LIBFT)) \
	$(subst libft_42/ft,ft,$(SRC_LIBFT_42)) \
	$(subst ft_printf/ft,ft,$(SRC_FT_PRINTF)) \
	$(subst get_next_line/get,get,$(SRC_GET_NEXT_LINE))

OBJ = $(subst .c,.o,$(OBJ1))

GW = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	$(GW) -I $(HEADER_MY_LIBFT) -I $(HEADER_LIBFT_42) -I \
		$(HEADER_FT_PRINTF) -c $(SRC_MY_LIBFT) $(SRC_LIBFT_42) \
		$(SRC_FT_PRINTF)
	$(GW) -D BUFFER_SIZE=$(BUFFER_SIZE) -D FD_SIZE=$(FD_SIZE) -I \
		$(HEADER_GET_NEXT_LINE) -c $(SRC_GET_NEXT_LINE)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

f: all clean

.PHONY: all clean fclean re f
