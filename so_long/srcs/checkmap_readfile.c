/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_readfile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:40:26 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/15 21:06:10 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	checkfile(char *file, t_data *data)
{
	int	fd;

	if (!ft_strrchr(file, '.') || (ft_strrchr(file, '.') && \
	ft_strncmp(ft_strrchr(file, '.'), ".ber", 5)))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	data->path = file;
	return (1);
}

static size_t	countline(char *file)
{
	int		fd;
	char	*s;
	size_t	count;

	count = 0;
	fd = open(file, O_RDONLY);
	s = get_next_line(fd);
	if (!s)
		return (0);
	while (s && ++count)
	{
		safefree(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static bool	initmap(t_data *data)
{
	int		fd;
	size_t	i;

	i = 0;
	fd = open(data->path, O_RDONLY);
	data->heigh = countline(data->path);
	if (!data->heigh)
		return (0);
	data->map = malloc (sizeof(char *) * (data->heigh + 1));
	if (!data->map)
		return (0);
	data->map[data->heigh] = NULL;
	while (i < data->heigh)
		data->map[i++] = get_next_line(fd);
	(void) get_next_line(fd);
	close (fd);
	return (1);
}

static bool	validmapsize(t_data *data)
{
	char	*s;
	size_t	i;

	i = 0;
	while (i < data->heigh)
	{
		s = data->map[i];
		if (data->width == 0)
			data->width = ft_strlen(s);
		if (ft_strlen(s) != data->width)
			return (0);
		while (*s)
			if (*s && !ft_strchr("01CPE\n", *(s++)))
				return (0);
		i++;
	}
	return (1);
}

int	checkmap_readfile(char *file, t_data *data)
{
	return (checkfile(file, data) && initmap(data) && validmapsize(data));
}
