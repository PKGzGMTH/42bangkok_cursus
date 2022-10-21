# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 09:57:59 by ptippaya          #+#    #+#              #
#    Updated: 2022/10/22 01:52:24 by ptippaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
INCLUDE = includes/stack.h
CC = gcc
CFLAG = -Wall -Wextra -Werror
SRCDIR = srcs/
SRC =	stack.c			\
		stack_input.c	\
		swap.c			\
		push.c			\
		rotate.c		\
		reversrotate.c	\
		push_swap3.c	\
		sort.c
SRCS = $(addprefix $(SRCDIR), $(SRC))
TESTSOURCE = $(SRCS) srcs/test.c

norm:
	@norminette -R CheckDefine $(INCLUDE)
	@norminette -R CheckForbiddenSourceHeader $(SRCS) srcs/main.c

test:
	@clear
	$(CC) $(CFLAG) -o test $(TESTSOURCE)
	./test

.PHONY: test
