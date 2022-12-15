/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:55:39 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/05 00:41:11 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"

static char	*get_next_read(int fd, char *dest)
{
	char	*buff;
	ssize_t	read_size;

	buff = NULL;
	read_size = 1;
	buff = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while ((!dest || dest[ft_strchrlen(dest, '\n')] != '\n') && read_size > 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1)
			break ;
		buff[read_size] = '\0';
		dest = ft_specialstrjoin(dest, buff);
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

static char	*get_next_dest(char *rest)
{
	char	*dest;
	ssize_t	i;

	i = 0;
	dest = NULL;
	if (rest && rest[ft_strchrlen(rest, '\n')] == '\n')
	{
		i = ft_strchrlen(rest, '\n');
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

static char	*get_next_rest(char	*rest)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dest = NULL;
	if (rest && rest[ft_strchrlen(rest, '\n')] == '\n')
	{
		dest = (char *) malloc (ft_strchrlen(rest, 0) - \
		ft_strchrlen(rest, '\n') + 1);
		j = ft_strchrlen(rest, '\n') + 1;
		while (rest[j])
			dest[i++] = rest[j++];
		dest[i] = '\0';
		if (rest)
			free (rest);
	}
	if (dest && !ft_strncmp(dest, "\0", 2))
	{
		free(dest);
		dest = NULL;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*dest;
	static char	*rest = NULL;

	dest = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!rest || rest[ft_strchrlen(rest, '\n')] != '\n')
		rest = get_next_read(fd, rest);
	dest = get_next_dest(rest);
	rest = get_next_rest(rest);
	return (dest);
}
