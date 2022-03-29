# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 15:52:45 by ptippaya          #+#    #+#              #
#    Updated: 2022/03/29 14:04:39 by ptippaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
H_FILE = libft.h
SRC_FILE =	ft_bzero.c		\
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
			ft_toupper.c
OBJECT_FILE = $(SRC_FILE:.c=.o)
GCC = gcc
GCCFLAG = -Wall -Werror -Wextra -std=c99
NORM = norminette
CFLAG = -R CheckForbiddenSourceHeader
HFLAG = -R CheckDefine
all: $(NAME)

$(NAME):
	@clear
	@printf 'all .c file:\n$(SRC_FILE)\n'
	@echo "compile all ft_*.c file to ft_.*o"
	@$(GCC) $(GCCFLAG) -c $(SRC_FILE)
	@echo "Done!"
	@echo "Convert all ft_*.o to Archive file libft.a"
	@ar -rcs $(NAME) $(OBJECT_FILE)
	@echo "Done!"

clean:
	@echo "Remove .o files : $(OBJECT_FILE)"
	@rm -rf $(OBJECT_FILE)
	@echo "Done!"

fclean: clean
	@echo "Remove .a files : $(NAME)"
	@rm -rf $(NAME)
	@echo "Done!"

re:	fclean all

norm:
	@clear
	@echo '------------------ norminette ------------------'
	@$(NORM) $(HFLAG) $(H_FILE)
	@$(NORM) $(CFLAG) $(SRC_FILE)
	@echo '------------------------------------------------'

test:
	@clear
	@$(GCC) $(SRC_FILE) -Wall -Werror -Wextra test.c -o a.out
	@./a.out; rm a.out
