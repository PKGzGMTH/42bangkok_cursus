/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:40:26 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/05 01:27:54 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	checkfile(char *file)
{
	int	fd;

	if (ft_strncmp(ft_strrchr(file, '.'), ".ber", 5))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static size_t	checksize(char *file)
{
	int		fd;
	int		readlen;
	int		width;
	int		height;
	char	*s;

	height = 0;
	fd = open(file, O_RDONLY);
	s = get_next_line(fd);
	if (!s)
		return (0);
	width = ft_strlen(s);
	readlen = ft_strlen(s);
	while (s)
	{
		if (readlen == width && ++height)
			readlen = ft_strlen(s);
		safefree(s);
		s = get_next_line(fd);
	}
	safefree(s);
	close(fd);
	if (readlen != width)
		return (0);
	return (height);
}

bool	checkmap(char *file, t_data *data)
{
	int	heigth;

	if (!checkfile(file))
		return (0);
	heigth = checksize(file);
	ft_printf("height: %d\n", heigth);
	if (!heigth)
		return (0);
	(void) data;
	return (1);
}
