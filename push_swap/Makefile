# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 09:57:59 by ptippaya          #+#    #+#              #
#    Updated: 2022/10/28 19:42:34 by ptippaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
INCLUDE = includes/stack.h
CC = gcc
CFLAG = -Wall -Wextra -Werror
SRCDIR = srcs/
OBJDIR = objs/
SRC =	stack.c			\
		stack_input.c	\
		swap.c			\
		push.c			\
		rotate.c		\
		reversrotate.c	\
		push_swap3.c	\
		sort.c			\
		main.c
SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))
TESTSOURCE = $(SRCS) srcs/test.c
all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) -c $(SRCS)
	mkdir -p objs
	mv $(OBJ) $(OBJDIR)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

norm:
	@norminette -R CheckDefine $(INCLUDE)
	@norminette -R CheckForbiddenSourceHeader $(SRCS) srcs/main.c

re: fclean $(NAME)

.PHONY: $(NAME) all norm clean fclean re
