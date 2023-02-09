/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:47:32 by ptippaya          #+#    #+#             */
/*   Updated: 2023/02/08 18:11:18 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	update_win(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->heigh)
	{
		x = 0;
		while (x < data->width)
		{
			putimg(data, x, y, data->map[y][x]);
			x++;
		}
		y++;
	}
}

static void	update_map(t_data *data, int mov_x, int mov_y)
{
	if (data->map[data->start.y + mov_y][data->start.x + mov_x] == '1')
		return ;
	if (data->map[data->start.y + mov_y][data->start.x + mov_x] == 'C')
		data->collectable -= 1;
	data->map[data->start.y][data->start.x] = '0';
	data->map[data->start.y + mov_y][data->start.x + mov_x] = 'P';
	if (data->map[data->exit.y][data->exit.x] != 'E')
		data->map[data->exit.y][data->exit.x] = 'E';
	data->start.x += mov_x;
	data->start.y += mov_y;
	update_win(data);
	if (data->start.x == data->exit.x && data->start.y == data->exit.y && \
	data->collectable == 0)
		destroy(data);
}

void	mlx_setup(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width * data->img_size, \
	data->heigh * data->img_size, "so_long");
	update_win(data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0L, destroy, data);
	mlx_loop(data->mlx);
}

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_data(data);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_data *data)
{
	if (!ft_strchr("wasd", keycode) && (keycode < 81 && 84 < keycode))
		return (0);
	(void) data;
	if (keycode == 'w' || (char) keycode == 82)
		update_map(data, 0, -1);
	if (keycode == 's' || (char) keycode == 84)
		update_map(data, 0, 1);
	if (keycode == 'a' || (char) keycode == 81)
		update_map(data, -1, 0);
	if (keycode == 'd' || (char) keycode == 83)
		update_map(data, 1, 0);
	return (1);
}
