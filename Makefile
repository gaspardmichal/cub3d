# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 20:55:11 by gamichal          #+#    #+#              #
#    Updated: 2020/12/10 15:00:47 by gamichal         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME				=	cub3D

LIBFT				=	libft/
FT_HEADER			=	libft/includes/libft.h
FT_SRCS				=	$(shell find libft -name "*.c")
MLX					=	minilibx/
SRCS_PATH			=	srcs/
OBJS_PATH			=	objs/
INCL_PATH			=	includes
HEADER				=	includes/cub3d.h

SRC					=	main.c					\
						cub3d.c					\
						init.c					\
						parse_map.c				\
						parse_resolution.c		\
						parse_texture.c			\
						parse_color.c			\
						check_map.c				\
						check_map_utils.c

SRCS 				= 	$(addprefix $(SRCS_PATH),$(SRC))
OBJS				=	$(patsubst $(SRCS_PATH)%.c,$(OBJS_PATH)%.o, $(SRCS))

RM					=	rm -rf
CC					=	clang
CFLAGS				=	-Wall -Wextra -Werror
FSANITIZE			=	-g3 -fsanitize=address
FTFLAGS				=	-L $(LIBFT) -l ft
MLXFLAGS			=	-g -L $(MLX) -l mlx -framework OpenGL -framework Appkit

$(OBJS_PATH)%.o		:	$(SRCS_PATH)%.c $(HEADER) 
						$(shell mkdir -p $(OBJS_PATH))
ifdef FSAN
						$(CC) $(CFLAGS) $(FSANITIZE) -c $< -o $@
else
						$(CC) $(CFLAGS) -c $< -o $@
endif

all					:	$(NAME)

$(NAME)				:	$(OBJS) $(FT_HEADER) $(FT_SRCS)
						@$(MAKE) -C $(MLX)
ifdef FSAN
						@$(MAKE) -C $(LIBFT) FSAN=1
						$(CC) $(CFLAGS) $(FSANITIZE) -o $@ $(OBJS) $(MLXFLAGS) $(FTFLAGS)
else
						@$(MAKE) -C $(LIBFT)
						$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLXFLAGS) $(FTFLAGS)
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
