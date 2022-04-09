/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwoowong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:28:57 by kwoowong          #+#    #+#             */
/*   Updated: 2022/04/04 21:53:09 by kwoowong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *previous_line)
{
	char	*buff;
	int		bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(previous_line, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		previous_line = ft_strjoin(previous_line, buff);
	}
	free(buff);
	return (previous_line);
}

char	*ft_get_current_line(char *current_line)
{
	char	*line;
	int		len;

	len = 0;
	if (!current_line[len])
		return (NULL);
	while (current_line[len] && current_line[len] != '\n')
		++len;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	len = 0;
	while (current_line[len] && current_line[len] != '\n')
	{
		line[len] = current_line[len];
		++len;
	}
	if (current_line[len] == '\n')
	{
		line[len] = '\n';
		++len;
	}
	line[len] = '\0';
	return (line);
}

char	*ft_clear_current_line(char	*current_line)
{
	char	*previous_line;
	int		len;
	int		i;

	len = 0;
	while (current_line[len] && current_line[len] != '\n')
		++len;
	if (!current_line[len])
	{
		free(current_line);
		return (NULL);
	}
	previous_line = malloc(sizeof(char) * (ft_strlen(current_line) - len + 1));
	if (!previous_line)
		return (NULL);
	++len;
	i = 0;
	while (current_line[len])
		previous_line[i++] = current_line[len++];
	previous_line[i] = '\0';
	free(current_line);
	return (previous_line);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*str;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_file(fd, str);
	if (!str)
		return (NULL);
	res = ft_get_current_line(str);
	str = ft_clear_current_line(str);
	return (res);
}
