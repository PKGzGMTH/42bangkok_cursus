/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:05:45 by ptippaya          #+#    #+#             */
/*   Updated: 2023/02/10 21:26:06 by ptippaya         ###   ########.fr       */
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
	{
		ft_putstr_fd("You must enter 2 Argument!\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (!checkmap_readfile(av[1], &data) || !checkmap_validpath(&data))
	{
		free_map(data.map);
		return (EXIT_FAILURE);
	}
	else
		mlx_setup(&data);
	free_map(data.map);
	return (0);
}
