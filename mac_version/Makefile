# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atemfack <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/01 00:36:50 by atemfack          #+#    #+#              #
#    Updated: 2020/08/02 19:10:12 by atemfack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= srcs/ft_parse_map.c srcs/ft_perror.c srcs/ft_parse_map_utils1.c \
			srcs/ft_parse_map_utils2.c srcs/main_utils1.c srcs/main_utils2.c \
			srcs/ft_init.c srcs/ft_init_utils1.c srcs/ft_init_utils2.c \
			srcs/ft_screenshot.c srcs/bmp.c srcs/ft_render_3D.c \
			srcs/ft_render_3D_utils1.c srcs/ft_render_3D_utils2.c \
			srcs/ft_render_3D_utils3.c srcs/main.c

OBJS		= $(SRCS:.c=.o)

INCLUDE		= includes

MLX			= mlx

LIBFT		= libft

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I $(INCLUDE) 

LIBS		= -lmlx -framework OpenGL -framework AppKit -lz

MLX_NAME	= libmlx.a

LIBFT_NAME	= libft.a

NAME		= cub3d

IMAGE		= screenshot.bmp

all:		$(NAME)

$(NAME):	$(MLX_NAME) $(LIBFT_NAME) $(OBJS)
			gcc -L $(MLX) $(CFLAGS) $(LIBS) $(LIBFT_NAME) $(MLX_NAME) \
				-o $(NAME) $(OBJS)

$(MLX_NAME):	
			@$(MAKE) -C $(MLX)
			@cp $(MLX)/$(MLX_NAME) .

$(LIBFT_NAME):	
			@$(MAKE) -C $(LIBFT)
			@cp $(LIBFT)/$(LIBFT_NAME) .

clean:
			@$(MAKE) -C $(MLX) fclean
			@$(MAKE) -C $(LIBFT) fclean
			$(RM) $(MLX_NAME) $(LIBFT_NAME) $(OBJS) $(IMAGE)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

f:			all clean

.PHONY:		all clean fclean re f
