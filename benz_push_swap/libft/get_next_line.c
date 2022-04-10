/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:05:19 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/22 23:13:33 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	buf;
	int		len;
	int		i;
	int		pos;

	line = "";
	len = 0;
	i = 0;
	pos = 1;
	while (pos > 0)
	{
		pos = read(fd, &buf, 1);
		if (pos < 0 || pos == 0)
			break ;
		line = ft_linedup(line, len++);
		line[i++] = buf;
		if (buf == '\n')
			break ;
	}
	if (pos < 0 || (pos == 0 && len == 0))
		return (0);
	line[i] = '\0';
	return (line);
}
