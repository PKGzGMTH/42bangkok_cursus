/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:47:32 by ptippaya          #+#    #+#             */
/*   Updated: 2023/02/04 11:11:53 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_setup(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 640, 480, "so_long");
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0L, destroy, data);
	mlx_loop(data->mlx);
}

static void	update_map(t_data *data, int mov_x, int mov_y)
{
	size_t	h;

	h = 0;
	if (data->map[data->start.y + mov_y][data->start.x + mov_x] == '1')
		return ;
	if (data->map[data->start.y + mov_y][data->start.x + mov_x] == 'C')
		data->collectable -= 1;
	data->map[data->start.y][data->start.x] = '0';
	data->map[data->start.y + mov_y][data->start.x + mov_x] = 'P';
	data->start.x += mov_x;
	data->start.y += mov_y;
	system("clear");
	while (h < data->heigh)
		ft_printf("%s\n", data->map[h++]);
	ft_printf("C remaining: %d\n", data->collectable);
	if (data->start.x == data->exit.x && data->start.y == data->exit.y && \
	data->collectable == 0)
		destroy(data);
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
