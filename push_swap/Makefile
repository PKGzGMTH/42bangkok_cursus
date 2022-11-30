# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 09:57:59 by ptippaya          #+#    #+#              #
#    Updated: 2022/12/01 01:30:07 by ptippaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
INCLUDE = includes/stack.h
CC = cc
CFLAG = -Wall -Wextra -Werror
SRCDIR = srcs/
OBJDIR = objs/
SRC =	stack.c			\
		stack_input.c	\
		swap.c			\
		push.c			\
		rotate.c		\
		reversrotate.c	\
		push_swap.c		\
		push_swap_1.c	\
		push_back.c		\
		push_back_range.c	\
		sorted_arr.c	\
		median.c		\
		util.c			\
		main.c
SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))
TESTSOURCE = $(SRCS) srcs/test.c
all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) -c $(SRCS); mkdir -p objs; mv $(OBJ) $(OBJDIR)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

norm:
	@norminette -R CheckDefine $(INCLUDE)
	@norminette -R CheckForbiddenSourceHeader $(SRCS) srcs/main.c

re: fclean $(NAME)

test: re
	@clear
	@python3 gen.py > ./gen.txt;
	./push_swap $$(cat ./gen.txt) > ./output.txt
.PHONY: $(NAME) all norm clean fclean re test
