/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:32:15 by ptippaya          #+#    #+#             */
/*   Updated: 2023/02/03 15:29:58 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	// printf("Hello from key_hook! %d\n", (char) keycode);
	if (keycode == 'w' || (char) keycode == 82)
		printf("up!\n");
	if (keycode == 's' || (char) keycode == 84)
		printf("down!\n");
	if (keycode == 'a' || (char) keycode == 81)
		printf("left!\n");
	if (keycode == 'd' || (char) keycode == 83)
		printf("right!\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "so_long");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
