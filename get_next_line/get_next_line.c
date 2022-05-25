/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:55:39 by ptippaya          #+#    #+#             */
/*   Updated: 2022/05/25 22:51:21 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_read(int fd, char *dest)
{
	;
}

int	get_next_rest(int fd, char *dest)
{
	;
}

char	*get_next_line(int fd)
{
	char		*dest;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	data = get_next_read();
}
