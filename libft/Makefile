# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptippaya <ptippaya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 15:52:45 by ptippaya          #+#    #+#              #
#    Updated: 2022/04/08 00:51:32 by ptippaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
H_FILE = libft.h
SRC_FILE =	ft_atoi.c		\
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
			ft_putnbr_fd.c
OBJECT_FILE = $(SRC_FILE:.c=.o)
GCC = gcc
GCCFLAG = -Wall -Werror -Wextra -std=c99
NORM = norminette
CFLAG = -R CheckForbiddenSourceHeader
HFLAG = -R CheckDefine
all: $(NAME)

$(NAME):
	@printf "\e[38;2;211;0;196mCompile all ft_*.c file to ft_*.o: \e[0m"
	@$(GCC) $(GCCFLAG) -c $(SRC_FILE)
	@printf "\e[38;2;158;240;39mDone!\n\e[0m"
	@printf "\e[38;2;211;0;196mArchive to file libft.a: \e[0m"
	@ar -rcs $(NAME) $(OBJECT_FILE)
	@printf "\e[38;2;158;240;39mDone!\n\e[0m"

clean:
	@printf "\e[38;2;211;0;196mRemove .o files: \e[0m"
	@rm -rf $(OBJECT_FILE)
	@printf "\e[38;2;158;240;39mDone!\n\e[0m"

fclean: clean
	@printf "\e[38;2;211;0;196mRemove $(NAME): \e[0m"
	@rm -rf $(NAME)
	@printf "\e[38;2;158;240;39mDone!\n\e[0m"

re:	fclean all

norm:
	@printf "\e[38;2;211;0;196m------------------ norminette ------------------\n\e[0m"
	@$(NORM) $(HFLAG) $(H_FILE)
	@$(NORM) $(CFLAG) $(SRC_FILE)
	@printf "\e[38;2;211;0;196m------------------------------------------------\n\e[0m"

test:
	@$(GCC) $(SRC_FILE) -Wall -Werror -Wextra test.c -o a.out
	@./a.out; rm a.out
