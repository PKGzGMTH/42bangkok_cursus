# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 15:52:45 by ptippaya          #+#    #+#              #
#    Updated: 2023/02/10 11:07:42 by ptippaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MYLIBFT = libft.a
INCLUDE =	./includes/libft.h		\
			./includes/so_long.h	\
			./includes/ft_printf.h	\
			./includes/get_next_line.h
LIBFT =	ft_atoi.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_strchr.c		\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c 		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		get_next_line_utils.c\
		get_next_line.c	\
		ft_printf.c		\
		ft_printf_util1.c\
		ft_printf_util2.c
LIBFTS = $(addprefix libft/, $(LIBFT))
LIBFTOBJ = $(LIBFT:.c=.o)

SRC =	main.c				\
		checkmap_readfile.c	\
		checkmap_validpath.c\
		utils.c				\
		mlx.c
SRCS = $(addprefix srcs/, $(SRC))
SRCOBJ = $(SRC:.c=.o)

CC = cc
CFLAG = -Wall -Wextra -Werror
MLXFLAG = -lmlx -lXext -lX11

all: $(NAME)

$(NAME):  libft
	@$(CC) -c $(CFLAG) $(SRCS) $(MLXFLAG) && ar -rcs $(NAME).a $(SRCOBJ) && mkdir -p objs && mv $(SRCOBJ) objs/
	@$(CC) $(CFLAG) -o $(NAME) $(NAME).a $(MYLIBFT) $(MLXFLAG)

libft:
	@$(CC) -c $(CFLAG) $(LIBFTS) && ar -rcs $(MYLIBFT) $(LIBFTOBJ) && mkdir -p objs && mv $(LIBFTOBJ) objs/

clean:
	rm -rf objs $(MYLIBFT) $(NAME).a

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: re
	# valgrind --leak-check=full --show-leak-kinds=all ./so_long strsstest.ber
	valgrind --leak-check=full --show-leak-kinds=all ./so_long map.ber


norm:
	@norminette -R CheckDefine $(INCLUDE)
	@norminette -R CheckForbiddenSourceHeader $(LIBFTS) $(SRCS)

.PHONY: all clean fclean bonus test norm re libft $(NAME)
