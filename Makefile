# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atemfack <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/02 18:47:51 by atemfack          #+#    #+#              #
#*   Updated: 2020/08/02 21:24:18 by atemfack         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME					= cub3d

UNAME					:= $(shell uname)

IMAGE					= screenshot.bmp

MAC_VERSION_FILE		= mac_version

LINUX_VERSION_FILE		= linux_version

# TODO: Implement a better OS checker
ifeq ($(UNAME), Linux)
	VERSION_FILE				= $(LINUX_VERSION_FILE)
else
	VERSION_FILE				= $(MAC_VERSION_FILE)
endif

RM						= rm -f

all:					$(NAME)

$(NAME):
						@$(MAKE) -C $(VERSION_FILE)
						@cp $(VERSION_FILE)/$(NAME) .

docker:					
						@docker build -t cub3d .
						@docker run --rm -v $(PWD):/cub3d cub3d

clean:
						@$(MAKE) -C $(VERSION_FILE) fclean
						$(RM) $(IMAGE)

fclean:					clean
						$(RM) $(NAME)

re:						fclean $(NAME)

f:						all clean

.PHONY:					all clean docker fclean re f
