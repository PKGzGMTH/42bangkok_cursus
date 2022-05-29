/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:55:39 by ptippaya          #+#    #+#             */
/*   Updated: 2022/05/29 16:25:53 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_read(int fd, char *rest)
{
	char	*buff;
	char	*dest;
	ssize_t	read_size;

	buff = NULL;
	dest = NULL;
	read_size = 1;
	while ((!dest || dest[ft_strchr(dest, '\n')] != '\n') && read_size)
	{
		buff = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1)
		{
			if (buff)
				free(buff);
			return (NULL);
		}
		buff[read_size] = '\0';
		dest = ft_strjoin(rest, buff);
	}
	if (!read_size && !*dest)
	{
		if (dest)
			free(dest);
		return (NULL);
	}
	return (dest);
}

char	*get_next_dest(char *rest)
{
	char	*dest;
	ssize_t	i;

	i = 0;
	dest = NULL;
	if (rest && rest[ft_strchr(rest, '\n')] == '\n')
	{
		i = ft_strchr(rest, '\n');
		dest = (char *) malloc (sizeof(char) * (i + 2));
		if (!dest)
			return (NULL);
		dest[i++ + 1] = '\0';
		while (--i >= 0)
			dest[i] = rest[i];
		return (dest);
	}
	else
		return (rest);
}

char	*get_next_rest(char	*rest)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dest = NULL;
	if (rest && rest[ft_strchr(rest, '\n')] == '\n')
	{
		dest = (char *) malloc (ft_strchr(rest, 0) - ft_strchr(rest, '\n') + 1);
		j = ft_strchr(rest, '\n') + 1;
		while (rest[j])
			dest[i++] = rest[j++];
		dest[i] = '\0';
	}
	if (rest)
		free (rest);
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*dest;
	static char	*rest = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!rest || rest[ft_strchr(rest, '\n')] != '\n')
		rest = get_next_read(fd, rest);
	dest = get_next_dest(rest);
	rest = get_next_rest(rest);
	return (dest);
}
