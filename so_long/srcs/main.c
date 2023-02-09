/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:05:45 by ptippaya          #+#    #+#             */
/*   Updated: 2023/02/08 18:13:35 by ptippaya         ###   ########.fr       */
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
		ft_printf("Map err!\n");
	else
	{
		ft_printf("map pass! heigh:%d width:%d\n", data.heigh, data.width);
		mlx_setup(&data);
		free_data(&data);
	}
	return (0);
}
