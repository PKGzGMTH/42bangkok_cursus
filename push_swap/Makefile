# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 09:57:59 by ptippaya          #+#    #+#              #
#    Updated: 2022/10/23 23:04:59 by ptippaya         ###   ########.fr        #
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
		sort.c
SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))
TESTSOURCE = $(SRCS) srcs/test.c
all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) -c $(SRCS)
	mkdir -p objs
	mv $(OBJ) $(OBJDIR)
	ar -rcs $(NAME).a $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) srcs/main.c $(NAME).a

clean:
	rm -rf $(OBJS) $(OBJDIR)

fclean: clean
	@rm -rf $(NAME).a $(NAME)

norm:
	@norminette -R CheckDefine $(INCLUDE)
	@norminette -R CheckForbiddenSourceHeader $(SRCS) srcs/main.c

re: fclean $(NAME)

test:
	@clear
	@$(CC) $(CFLAG) -o test.out $(TESTSOURCE)
	./test.out

.PHONY: $(NAME) all norm test clean fclean re
