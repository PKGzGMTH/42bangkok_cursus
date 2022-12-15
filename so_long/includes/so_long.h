/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:41:49 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/15 21:14:12 by ptippaya         ###   ########.fr       */
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

typedef struct s_position
{
	size_t	x;
	size_t	y;
}	t_posotion;

typedef struct s_data {
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

size_t	init_position(t_posotion *p, size_t x, size_t y);
void	safefree(void *content);

#endif
