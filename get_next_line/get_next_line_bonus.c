/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:55:39 by ptippaya          #+#    #+#             */
/*   Updated: 2022/06/10 23:30:43 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_read(int fd, char *dest)
{
	char	*buff;
	ssize_t	read_size;

	buff = NULL;
	read_size = 1;
	buff = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while ((!dest || dest[ft_strchr(dest, '\n')] != '\n') && read_size > 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1)
			break ;
		buff[read_size] = '\0';
		dest = ft_strjoin(dest, buff);
	}
	free (buff);
	if (!read_size && !*dest)
	{
		if (dest)
			free(dest);
		dest = NULL;
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
		i = ft_strchr(rest, '\n') + 1;
		dest = (char *) malloc (sizeof(char) * (i + 1));
		if (!dest)
			return (NULL);
		dest[i] = '\0';
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
		if (rest)
			free (rest);
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	t_list			*buff;
	char			*dest;

	buff = NULL;
	dest = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = get_next_list(&list, fd);
	if (!buff->rest || buff->rest[ft_strchr(buff->rest, '\n')] != '\n')
		buff->rest = get_next_read(fd, buff->rest);
	dest = get_next_dest(buff->rest);
	buff->rest = get_next_rest(buff->rest);
	get_next_clean(&list);
	return (dest);
}
