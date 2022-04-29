# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 12:59:55 by ptippaya          #+#    #+#              #
#    Updated: 2022/04/28 20:29:27 by ptippaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

์NAME = get_next_line
SRC =	../get_next_line.c				\
		../get_next_line_utils.c
BONUS =	../get_next_line_bonus.c		\
		../get_next_line_utils_bonus.c
HSRC =	../get_next_line.h
HBONUS =../get_next_line_bonus.h
CC = gcc
CCFLAG = -Wall -Wextra -Werror
BUFF = -D BUFFER_SIZE=42
NORM = norminette
CFLAG = -R CheckForbiddenSourceHeader
HFLAG = -R CheckDefine

$(NAME): all

all:
	@clear
	@$(CC) $(CCFLAG) $(BUFF) $(SRC) main.c
	@./a.out < test.txt; rm a.out
	@printf "\e[38;2;158;240;39m\n--------------------- Done! ---------------------\n\e[0m"

leaks:
	@clear
	@$(CC) $(CCFLAG) $(BUFF) $(SRC) main.c
	@valgrind --leak-check=full ./a.out < test.txt; rm a.out
	@printf "\e[38;2;158;240;39m\n--------------------- Done! ---------------------\n\e[0m"

norm:
	@clear
	@printf "\e[38;2;211;0;196m------------------ norminette ------------------\n\e[0m"
	@$(NORM) $(HFLAG) $(HSRC)	#$(HBONUS)
	@printf "\e[38;2;211;0;196m---------------------- .c ----------------------\n\e[0m"
	@$(NORM) $(CFLAG) $(SRC)	#$(BONUS)
	@printf "\e[38;2;211;0;196m------------------------------------------------\n\e[0m"
