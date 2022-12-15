/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:05:45 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/15 20:55:57 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	startup_init(t_data *data)
{
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

static void	free_data(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map && data->map[i])
		safefree(data->map[i++]);
	safefree(data->map);
}

int	main(int ac, char **av)
{
	t_data	data;

	startup_init(&data);
	if (ac != 2)
		return (0);
	if (!checkmap_readfile(av[1], &data) || !checkmap_validpath(&data))
		ft_printf("Map err\n");
	ft_printf("finish\n");
	free_data(&data);
	return (0);
}
