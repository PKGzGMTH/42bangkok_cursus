# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 13:19:16 by ptippaya          #+#    #+#              #
#    Updated: 2022/06/16 20:05:13 by ptippaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_printf_util1.c ft_printf_util2.c
OBJ_SRC = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
NORM = norminette
CNORM = -R CheckForbiddenSourceHeader
HNORM = -R CheckDefine

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar -rcs $(NAME) $(OBJ_SRC)

norm:
	@$(NORM) $(CNORM) $(SRC)
	@$(NORM) $(HNORM) ft_printf.h

clean:
	@rm -rf $(OBJ_SRC)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: re clean
	@clear; $(CC) $(CFLAGS) test.c -L. $(NAME) && ./a.out && rm a.out

.PHONY: all clean fclean re test norm
