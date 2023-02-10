/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_validpath.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:59:15 by ptippaya          #+#    #+#             */
/*   Updated: 2023/02/10 21:09:50 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	check_wall(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->width)
	{
		if (data->map[0][i] != '1' || data->map[data->heigh - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < data->heigh)
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static bool	chech_obj(t_data *data)
{
	size_t	x;
	size_t	y;
	size_t	p;
	size_t	e;

	p = 0;
	e = 0;
	y = 1;
	while (y < data->heigh - 1 && p < 2 && e < 2)
	{
		x = 1;
		while (x < data->width - 1 && p < 2 && e < 2)
		{
			if (data->map[y][x] == 'C')
				data->collectable++;
			if (data->map[y][x] == 'P')
				p += init_position(&(data->start), x, y);
			if (data->map[y][x] == 'E')
				e += init_position(&(data->exit), x, y);
			x++;
		}
		y++;
	}
	return (data->collectable > 0 && p == 1 && e == 1);
}

static char	**walkpath(t_data *data, char **map, size_t x, size_t y)
{
	if (x < 1 || x > data->width - 1 || y < 1 || y > data->heigh - 1 || \
	!ft_strchr("CPE0", map[y][x]))
		return (map);
	map[y][x] = ' ';
	map = walkpath(data, map, x, y + 1);
	map = walkpath(data, map, x, y - 1);
	map = walkpath(data, map, x + 1, y);
	map = walkpath(data, map, x - 1, y);
	return (map);
}

static bool	check_walkpath(t_data *data)
{
	char	**map;
	size_t	x;
	size_t	y;

	y = 1;
	map = mapcpy(data);
	map = walkpath(data, map, data->start.x, data->start.y);
	while (y < data->heigh - 1)
	{
		x = 1;
		while (x < data->width - 1)
		{
			if (ft_strchr("CPE", map[y][x]))
			{
				free_map(map);
				return (0);
			}
			x++;
		}
		y++;
	}
	free_map(map);
	return (1);
}

int	checkmap_validpath(t_data *data)
{
	if (!check_wall(data))
	{
		ft_putstr_fd("Map isn't closed/surrounded by walls!\n", STDERR_FILENO);
		return (0);
	}
	if (!chech_obj(data))
	{
		ft_putstr_fd("Map must contain 1 exit, at least 1 collectible, \
and 1 starting!\n", STDERR_FILENO);
		return (0);
	}
	if (!check_walkpath(data))
	{
		ft_putstr_fd("Map is Invalid path!\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}
