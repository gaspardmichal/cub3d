# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 20:55:11 by gamichal          #+#    #+#              #
#    Updated: 2021/01/04 10:27:33 by gamichal         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME				=	cub3D

LIBFT				=	libft/
LIBFT_HEADER		=	libft/includes/libft.h
LIBFT_SRCS			=	$(shell find libft -name "*.c")
SRCS_PATH			=	srcs/
OBJS_PATH			=	objs/
HEADER				=	includes/cub3d.h

SRC					=	main.c					\
						cub3d.c					\
						init.c					\
						init2.c					\
						parse_line.c			\
						parse_res.c				\
						parse_txt.c				\
						parse_col.c				\
						parse_map.c				\
						check_walls.c

SRCS 				= 	$(addprefix $(SRCS_PATH),$(SRC))
OBJS				=	$(patsubst $(SRCS_PATH)%.c,$(OBJS_PATH)%.o, $(SRCS))

RM					=	rm -rf
CC					=	clang
FSANITIZE			=	-g3 -fsanitize=address
CFLAGS				=	-g3 -Wall -Wextra -Werror

OS_NAME				=	$(shell uname -s)

ifeq ($(OS_NAME), Darwin)
		MLX			=	mlx_mac
		MLX_FLAGS	=	-L $(MLX) -l mlx -framework OpenGL -framework Appkit
		DEFINES		=	-D OS_LINUX=0
else
		MLX			=	mlx_linux
		MLX_FLAGS	=	-L $(MLX) -l mlx -l Xext -l X11 -l bsd
		DEFINES		=	-D OS_LINUX=1
endif

LIBFT_FLAGS			=	-L $(LIBFT) -l ft

$(OBJS_PATH)%.o		:	$(SRCS_PATH)%.c $(HEADER) 
						$(shell mkdir -p $(OBJS_PATH))
ifdef FSAN
						$(CC) $(DEFINES) $(CFLAGS) $(FSANITIZE) -c $< -o $@
else
						$(CC) $(DEFINES) $(CFLAGS) -c $< -o $@
endif

all					:	$(NAME)

$(NAME)				:	$(OBJS) $(LIBFT_HEADER) $(LIBFT_SRCS)
						@$(MAKE) -C $(MLX)
ifdef FSAN
						@$(MAKE) -C $(LIBFT) FSAN=1
						$(CC) $(CFLAGS) $(FSANITIZE) -o $@ $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)
else
						@$(MAKE) -C $(LIBFT)
						$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)
endif

clean				:
						$(RM) $(NAME) $(OBJS_PATH)
						@$(MAKE) $@ -C $(LIBFT)
						@$(MAKE) $@ -C $(MLX)

fclean				:	clean
						$(RM) $(NAME) 						
						@$(MAKE) $@ -C $(LIBFT)

re					:	fclean all

.PHONY				:	all clean fclean re
