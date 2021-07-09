# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atemfack <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/01 00:36:50 by atemfack          #+#    #+#              #
#*   Updated: 2020/08/06 18:21:25 by atemfack         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

SRCS		= srcs/ft_parse_map.c srcs/ft_perror.c srcs/ft_parse_map_utils1.c \
			srcs/ft_parse_map_utils2.c srcs/main_utils1.c srcs/main_utils2.c \
			srcs/ft_init.c srcs/ft_init_utils1.c srcs/ft_init_utils2.c \
			srcs/ft_screenshot.c srcs/bmp.c srcs/ft_render_3d.c \
			srcs/ft_render_3d_utils1.c srcs/ft_render_3d_utils2.c \
			srcs/ft_render_3d_utils3.c srcs/main.c

OBJS		= $(SRCS:.c=.o)

INCLUDE		= includes

LIBMLX_DIR	= mlx

LIBFT_DIR	= libft

CC			= gcc

RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror -I $(INCLUDE) 

LIBS		= -lmlx -lXext -lX11 -lm -lbsd -L$(LIBMLX_DIR) -L$(LIBFT_DIR)

LIBMLX		= libmlx.a

LIBFT		= libft.a

IMAGE		= screenshot.bmp

all:		$(NAME)

$(NAME):	$(LIBMLX) $(LIBFT) $(OBJS)
			gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(LIBMLX_DIR)/$(LIBMLX) \
						$(LIBFT_DIR)/$(LIBFT)

$(LIBFT_DIR):
			@git clone https://github.com/airseneo/libft.git $(LIBFT_DIR)

$(LIBMLX_DIR):
			@git clone https://github.com/42Paris/minilibx-linux.git \
				 		$(LIBMLX_DIR)

$(LIBMLX):	$(LIBMLX_DIR)
			@$(MAKE) --no-print-directory -C $(LIBMLX_DIR)

$(LIBFT):	$(LIBFT_DIR)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

clean:
			$(RM) $(OBJS) $(IMAGE)
			@$(MAKE) --no-print-directory -C $(LIBMLX_DIR) clean
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean


fclean:		clean
			@$(RM) $(NAME) $(LIBFT_DIR) $(LIBMLX_DIR)

re:			fclean $(NAME)

f:			all clean

.PHONY:		all clean fclean re f
