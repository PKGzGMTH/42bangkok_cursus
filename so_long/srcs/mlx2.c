/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:25:06 by ptippaya          #+#    #+#             */
/*   Updated: 2023/02/08 18:11:52 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	putimg(t_data *data, size_t x, size_t y, char c)
{
	void	*img;
	char	*path;

	(void) c;
	if (c == '0')
		path = "./textures/0.xpm";
	else if (c == '1')
		path = "./textures/1.xpm";
	else if (c == 'C')
		path = "./textures/C.xpm";
	else if (c == 'P')
		path = "./textures/P.xpm";
	else if (c == 'E')
		path = "./textures/E.xpm";
	else
		return ;
	img = mlx_xpm_file_to_image(data->mlx, path, \
	&data->img_size, &data->img_size);
	mlx_put_image_to_window(data->mlx, data->win, img, \
	(int)x * data->img_size, (int)y * data->img_size);
	mlx_destroy_image(data->mlx, img);
}
