/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:52:20 by ptippaya          #+#    #+#             */
/*   Updated: 2022/06/10 23:31:18 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				fd;
	char			*rest;
	struct s_list	*next;
}	t_list;

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strchr(char *s, char c);

char	*get_next_line(int fd);
char	*get_next_rest(char	*rest);
char	*get_next_dest(char *rest);
char	*get_next_read(int fd, char *dest);
void	get_next_clean(t_list **list);
t_list	*get_next_list(t_list **list, int fd);

#endif
