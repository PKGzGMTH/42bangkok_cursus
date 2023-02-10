/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:05:45 by ptippaya          #+#    #+#             */
/*   Updated: 2023/02/10 11:12:00 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	startup_init(t_data *data)
{
	data->img_size = 64;
	data->path = NULL;
	data->map = NULL;
	data->heigh = 0;
	data->width = 0;
	data->collectable = 0;
	data->start.x = 0;
	data->start.y = 0;
	data->exit.x = 0;
	data->exit.y = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	startup_init(&data);
	if (ac != 2)
		return (0);
	if (!checkmap_readfile(av[1], &data) || !checkmap_validpath(&data))
		ft_putstr_fd("Error!\n", STDERR_FILENO);
	else
		mlx_setup(&data);
	free_map(data.map);
	ft_printf("Mapsize heigh:%d width:%d\n", data.heigh, data.width);
	return (0);
}
