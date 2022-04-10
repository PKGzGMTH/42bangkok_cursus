# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brangrae <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 09:29:30 by brangrae          #+#    #+#              #
#    Updated: 2022/04/10 19:08:48 by brangrae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= push_swap.c push_swap_solve.c push_swap_util1.c push_swap_util2.c \
	  push_swap_util3.c push_swap_util4.c push_swap_util5.c \
	  push_swap_util6.c push_swap_util7.c  push_swap_util8.c \
	  push_swap_solve1.c

SRCS_B	= checker.c push_swap_read.c push_swap_util1.c push_swap_util2.c \
	  push_swap_util3.c push_swap_util4.c push_swap_util5.c

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

HEAD	= libft

NAME	= push_swap

NAME_B	= checker

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

LIB	= -lft

LIBFT	= libft.a

MAKE	= make

.c.o:
		${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${LIBFT} ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB} -L ${HEAD}

${NAME_B}:	${LIBFT} ${OBJS_B}
		${CC} ${CFLAGS} -o ${NAME_B} ${OBJS_B} ${LIB} -L ${HEAD}

${LIBFT}:
		${MAKE} -sC ${HEAD}

all:		${NAME}

clean:
		${MAKE} clean -sC ${HEAD}
		${RM} ${OBJS} ${OBJS_B}

fclean:		clean
		${RM} ${HEAD}/${LIBFT}
		${RM} ${NAME} ${NAME_B}

re:		fclean all

bonus:		${NAME_B}

.PHONY:		all clean fclean re bonus
