/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:55:39 by ptippaya          #+#    #+#             */
/*   Updated: 2022/05/20 19:57:32 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	nextchr(char *s, char c)
{
	size_t	size;

	size = 0;
	while (s && s[size] && s[size] != c)
		size++;
	if (s[size] == c)
		return (size);
	else
		return (0);
}

int	get_next_read(int fd, char **dest, char **old)
{
	char		*buff;
	static int	state = 1;

	buff = NULL;
	while (state)
	{
		buff = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (0);
		if (!read(fd, buff, BUFFER_SIZE))
		{
			if (buff && *buff)
			{
				*dest = ft_strjoin(*old, buff);
				state = 0;
				return (1);
			}
			else
				return (0);
		}
		else
			*old = ft_strjoin(*old, buff);
		if ((*old)[nextchr(*old, '\n')] == '\n')
		{
			*dest = ft_substr(*old, 0, nextchr(*old, '\n') + 1);
			buff = ft_substr(*old, nextchr(*old, '\n') + 1, \
			nextchr(*old, '\0') - nextchr(*old, '\n') + 1);
			if (*old)
			{
				free (*old);
				*old = NULL;
			}
			*old = buff;
			break ;
		}
	}
	return (state);
}

char	*get_next_line(int fd)
{
	char		*dest;
	static char	*old = NULL;

	dest = NULL;
	if (BUFFER_SIZE <= 0 || !get_next_read(fd, &dest, &old))
	{
		return (NULL);
	}
	return (dest);
}
