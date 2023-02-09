/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:41:49 by ptippaya          #+#    #+#             */
/*   Updated: 2023/02/07 14:49:13 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../includes/libft.h"
# include "../includes/ft_printf.h"
# include "../includes/get_next_line.h"

typedef struct s_position {
	size_t	x;
	size_t	y;
}	t_posotion;

typedef struct s_data {
	int			img_size;
	void		*mlx;
	void		*win;
	char		*path;
	char		**map;
	size_t		heigh;
	size_t		width;
	size_t		collectable;
	t_posotion	start;
	t_posotion	exit;
}	t_data;

int		checkmap_readfile(char *file, t_data *data);
int		checkmap_validpath(t_data *data);
int		key_hook(int keycode, t_data *data);
int		destroy(t_data *data);

size_t	init_position(t_posotion *p, size_t x, size_t y);
void	safefree(void *content);
void	free_map(char **map);
void	free_data(t_data *data);
void	mlx_setup(t_data *data);
char	**mapcpy(t_data *data);
void	putimg(t_data *data, size_t x, size_t y, char c);

#endif
