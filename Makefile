# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 12:33:00 by lvicino           #+#    #+#              #
#    Updated: 2024/06/03 19:36:15 by lvicino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

LIBFT		=	libft/libft.a

MLX			=	mlx_linux

OBJ_DIR		=	obj


SRC_DIR		=	src

SRC			=	so_long.c \
				so_long_utils.c \
				check_map.c \
				check_components.c \
				pathfinding.c \
				init_image.c \
				init_num.c \
				enemy.c \
				coin.c \
				steps.c \
				win_lose.c \
				draw.c \
				events.c \
				move_player.c


SRC			:=	$(SRC:%=$(SRC_DIR)/%)
OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3
INCLUDE		=	-I include -I libft/include -I libft/ft_printf/include -I libft/get_next_line/include -I mlx_linux

MAKEFLAGS	+=	--no-print-directory
DIR_DUP		=	mkdir -p $(@D)


all		:	foo $(NAME)

$(NAME)		:	$(OBJ)
	@if [ ! -e "$(LIBFT)" ]; then \
		make -C libft; \
	fi
	$(CC) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -I mlx_linux -lXext -lX11 -lm -lz -o $(NAME)

foo		:
	@if [ ! -d "$(MLX)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git ; \
		mv minilibx-linux $(MLX) ; \
		make -C $(MLX) ; \
	else \
		echo "make: Nothing to be done for 'all'."; \
	fi

$(OBJ_DIR)/%.o		:	$(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<


%.o: %.c
	$(CC) -Wall -Wextra -Werror -I /usr/include -I mlx_linux -O3 -c $< -o $@


clean	:
	if [ -d "$(OBJ_DIR)" ]; then \
		rm -f $(OBJ); \
		rmdir $(OBJ_DIR); \
		make clean -C libft; \
		make clean -C mlx_linux; \
	fi

fclean	:	clean
	if [ -e "$(NAME)" ]; then \
		rm -f $(NAME); \
	fi
	if [ -e "$(LIBFT)" ]; then \
		make fclean -C libft; \
	fi
	@if [ -d "$(MLX)" ]; then \
		rm -rf $(MLX); \
	fi

re		:	fclean all

.PHONY	:	clean fclean re
.SILENT	:	clean fclean
