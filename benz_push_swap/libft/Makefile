# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brangrae <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 23:03:36 by brangrae          #+#    #+#              #
#    Updated: 2022/03/17 23:47:13 by brangrae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ${wildcard *.c}

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC	= gcc

RM	= rm -f

AR	= ar -rc

INDEX	= ranlib

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${AR} ${NAME} ${OBJS}
		${INDEX} ${NAME}

all:		${NAME}

clean:
		${RM} ${OBJS} ${OBJS_B}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
