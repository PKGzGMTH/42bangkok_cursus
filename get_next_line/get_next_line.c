/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:55:39 by ptippaya          #+#    #+#             */
/*   Updated: 2022/05/21 00:48:16 by ptippaya         ###   ########.fr       */
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

int	get_next_read(int fd, char **dest)
{
	char		*raw;
	size_t		read_size;

	raw = NULL;
	raw = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!raw)
		return (0);
	read_size = read(fd, raw, BUFFER_SIZE);
	if (!read_size)
	{
		free(raw);
		return (0);
	}
	else if (read_size < BUFFER_SIZE)
	{
		*dest = (char *)ft_calloc(read_size + 1, sizeof(char));
		ft_strlcpy(*dest, raw, read_size);
		free(raw);
	}
	else
		*dest = raw;
	return (1);
}

char	*get_next_line(int fd)
{
	char		*dest;
	char		*buff;
	static char	*remain = NULL;

	dest = NULL;
	buff = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (!remain || (remain && remain[nextchr(remain, '\n')] != '\n'))
	{
		// printf("%s\n",remain);
		get_next_read(fd, &buff);
		remain = ft_strjoin(remain, buff);
	}
	buff = remain;
	if (buff && nextchr(buff, '\n') == '\n')
	{
		dest = ft_substr(buff, 0, nextchr(buff, '\n') + 1);
		remain = ft_substr(buff, nextchr(buff, '\n') + 1, \
		nextchr(buff, '\0') - nextchr(buff, '\n') + 1);
		free(buff);
	}
	else
		return (remain);
	return (dest);
}
