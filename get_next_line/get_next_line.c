/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:55:39 by ptippaya          #+#    #+#             */
/*   Updated: 2022/04/21 22:30:30 by ptippaya         ###   ########.fr       */
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

int	get_next_line_read(int fd, char **dest, char **old)
{
	char	*temp;

	temp = NULL;
	while (!*old || !**old || (*old)[nextchr(*old, '\n')] != '\n')
	{
		temp = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!temp || !read(fd, temp, BUFFER_SIZE) || (temp && !*temp))
		{
			free (temp);
			return (0);
		}
		*old = ft_strjoin(*old, temp);
	}
	*dest = ft_substr(*old, 0, nextchr(*old, '\n') + 1);
	temp = ft_substr(*old + nextchr(*old, '\n') + 1, 0, nextchr(*old, 0));
	free(*old);
	*old = temp;
	return (1);
}

char	*get_next_line(int fd)
{
	char		*dest;
	static char	*old = NULL;

	dest = NULL;
	if (BUFFER_SIZE <= 0 || !get_next_line_read(fd, &dest, &old) \
		|| (!*old && !*dest))
	{
		free (dest);
		free (old);
		return (0);
	}
	return (dest);
}
