# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 18:13:37 by gamichal          #+#    #+#              #
#    Updated: 2020/03/06 13:44:17 by gamichal         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME				=	libft.a

SRCS_PATH			=	srcs/
OBJS_PATH			=	objs/
INCL_PATH			=	includes
HEADER				=	includes/libft.h

SRC					=	char/ft_isalnum.c				\
						char/ft_isalpha.c				\
						char/ft_isascii.c				\
						char/ft_isdigit.c				\
						char/ft_islower.c				\
						char/ft_isprint.c				\
						char/ft_isspace.c				\
						char/ft_isupper.c				\
						char/ft_putchar.c				\
						char/ft_tolower.c				\
						char/ft_toupper.c				\
						fd/ft_putchar_fd.c				\
						fd/ft_putendl_fd.c				\
						fd/ft_putnbr_fd.c				\
						fd/ft_putstr_fd.c				\
						gnl/get_next_line.c				\
						gnl/get_next_line_utils.c		\
						int/ft_itoa.c					\
						int/ft_itoa_base.c				\
						int/ft_putnbr.c					\
						lst/ft_lstadd_back.c			\
						lst/ft_lstadd_front.c			\
						lst/ft_lstclear.c				\
						lst/ft_lstdelone.c				\
						lst/ft_lstiter.c				\
						lst/ft_lstlast.c				\
						lst/ft_lstmap.c					\
						lst/ft_lstnew.c					\
						lst/ft_lstsize.c				\
						mem/ft_bzero.c					\
 						mem/ft_calloc.c					\
						mem/ft_exit.c					\
						mem/ft_free.c					\
 						mem/ft_memccpy.c				\
 						mem/ft_memchr.c					\
 						mem/ft_memcmp.c					\
						mem/ft_memcpy.c					\
 						mem/ft_memmove.c				\
 						mem/ft_memset.c					\
						ft_printf/ft_printf.c			\
  						ft_printf/ft_printf_utils.c		\
  						ft_printf/parse_modif.c			\
  						ft_printf/parse_spec.c			\
  						ft_printf/print_c.c				\
						ft_printf/print_di.c			\
  						ft_printf/print_di_flags.c		\
  						ft_printf/print_di_no_flags.c	\
  						ft_printf/print_p.c				\
  						ft_printf/print_p_flag.c		\
  						ft_printf/print_p_no_flag.c		\
  						ft_printf/print_percent.c		\
  						ft_printf/print_s.c				\
  						ft_printf/print_s_utils.c		\
  						ft_printf/print_ux.c			\
  						ft_printf/print_ux_flags.c		\
  						ft_printf/print_ux_no_flags.c	\
						str/ft_atoi.c					\
   						str/ft_split.c					\
   						str/ft_strcat.c					\
   						str/ft_strchr.c					\
						str/ft_strcmp.c					\
   						str/ft_strcpy.c					\
   						str/ft_strdup.c					\
   						str/ft_strjoin.c				\
   						str/ft_strlcat.c				\
   						str/ft_strlcpy.c				\
   						str/ft_strlen.c					\
   						str/ft_strmapi.c				\
   						str/ft_strncmp.c				\
   						str/ft_strnstr.c				\
   						str/ft_strrchr.c				\
   						str/ft_strtrim.c				\
   						str/ft_substr.c

SRCS				=	$(addprefix $(SRCS_PATH),$(SRC))
OBJS				=	$(patsubst $(SRCS_PATH)%.c,$(OBJS_PATH)%.o, $(SRCS))
RM					=	rm -rf
AR					=	ar rc
CFLAGS				=	-Wall -Wextra -Werror
FSANITIZE			=	-g3 -fsanitize=address
CC					=	clang

$(OBJS_PATH)%.o		:	$(SRCS_PATH)%.c $(HEADER)
						$(shell mkdir -p $(OBJS_PATH))
						$(shell mkdir -p $(OBJS_PATH)/char)
						$(shell mkdir -p $(OBJS_PATH)/fd)
						$(shell mkdir -p $(OBJS_PATH)/gnl)
						$(shell mkdir -p $(OBJS_PATH)/int)
						$(shell mkdir -p $(OBJS_PATH)/lst)
						$(shell mkdir -p $(OBJS_PATH)/mem)
						$(shell mkdir -p $(OBJS_PATH)/ft_printf)
						$(shell mkdir -p $(OBJS_PATH)/str)
ifdef FSAN
						$(CC) $(CFLAGS) $(FSANITIZE) -c $< -o $@
else
						$(CC) $(CFLAGS) -c $< -o $@
endif

all					:	$(NAME)

$(NAME)				:	$(OBJS)
						$(AR) $(NAME) $(OBJS)
						ranlib $(NAME)

clean				:
						$(RM) $(OBJS_PATH)

fclean				:	clean
						$(RM) $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re
