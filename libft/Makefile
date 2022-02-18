# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 15:52:45 by ptippaya          #+#    #+#              #
#    Updated: 2022/02/18 13:29:56 by ptippaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
H_FILE = $(shell find . -type f -name "*.h")
SRC_FILE = $(shell find . -type f -name "ft_*.c")
OBJECT_FILE = $(shell find . -type f -name "ft_*.o")
GCC = gcc
GCCFLAG = -Wall -Werror -Wextra -std=c99
NORM = norminette
CFLAG = -R CheckForbiddenSourceHeader
HFLAG = -R CheckDefine
all: $(NAME)

$(NAME):
	@clear
	@echo "compile all ft_*.c file to ft_.*o"
	@$(GCC) $(GCCFLAG) -c $(SRC_FILE)
	@echo "Done!"
	@echo "Convert all ft_*.o to Archive file libft.a"
	@ar rcs $(NAME) $(OBJECT_FILE)
	@echo "Done"

clean:
	@echo "Remove .o files : $(OBJECT_FILE)"
	@rm -rf $(OBJECT_FILE)
	@echo "Done!"

fclean: clean
	@echo "Remove .a files : $(NAME)"
	@rm -rf $(NAME)
	@echo "Done"

re:	fclean all


norm:
	@clear
	@echo '------------------ norminette ------------------'
	@$(NORM) $(HFLAG) $(H_FILE)
	@$(NORM) $(CFLAG) $(SRC_FILE)
	@echo '------------------------------------------------'
