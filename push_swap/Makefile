# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 09:57:59 by ptippaya          #+#    #+#              #
#    Updated: 2022/12/02 13:02:15 by ptippaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
INCLUDE = includes/push_swap.h includes/push_swap_bonus.h
CC = cc
CFLAG = -Wall -Wextra -Werror
SRCDIR = srcs/
OBJDIR = objs/

SRC =	stack.c				\
		stack_input.c		\
		swap.c				\
		push.c				\
		rotate.c			\
		reversrotate.c		\
		push_swap.c			\
		push_swap_1.c		\
		push_back.c			\
		push_back_range.c	\
		sorted_arr.c		\
		median.c			\
		util.c				\
		main.c

SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))

BONUSSRC =	main_bonus.c		\
			stack_bonus.c		\
			stack_input_bonus.c	\
			swap_bonus.c		\
			push_bonus.c		\
			rotate_bonus.c		\
			reversrotate_bonus.c\
			checker_bonus.c

BONUSSRCS = $(addprefix $(SRCDIR), $(BONUSSRC))
BONUSOBJ = $(BONUSSRC:.c=.o)
BONUSOBJS = $(addprefix $(OBJDIR), $(BONUSOBJ))

TESTSOURCE = $(SRCS) srcs/test.c
all: $(NAME) bonus

$(NAME):
	@$(CC) $(CFLAG) -c $(SRCS); mkdir -p objs; mv $(OBJ) $(OBJDIR)
	@$(CC) $(CFLAG) -o $(NAME) $(OBJS)

bonus:
	@$(CC) $(CFLAG) -c $(BONUSSRCS); mkdir -p objs; mv $(BONUSOBJ) $(OBJDIR)
	@$(CC) $(CFLAG) -o checker $(BONUSOBJS)

clean:
	@rm -rf $(OBJS) $(BONUSOBJS) $(OBJDIR)

fclean: clean
	@rm -rf $(NAME) checker

norm:
	@norminette -R CheckDefine $(INCLUDE)
	@norminette -R CheckForbiddenSourceHeader $(SRCS) $(BONUSSRCS)

re: fclean $(NAME)


.PHONY: $(NAME) all norm bonus clean fclean re test
