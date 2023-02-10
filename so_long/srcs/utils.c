/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:21:00 by ptippaya          #+#    #+#             */
/*   Updated: 2023/02/04 11:05:22 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	safefree(void *content)
{
	if (content)
		free(content);
}

void	free_map(char **map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (map && map[i])
		safefree(map[i++]);
	safefree(map);
}

size_t	init_position(t_posotion *p, size_t x, size_t y)
{
	p->x = x;
	p->y = y;
	return (1);
}

char	**mapcpy(t_data *data)
{
	char	**dest;
	size_t	h;

	h = 0;
	dest = (char **) malloc (sizeof(char *) * (data->heigh + 1));
	if (!dest)
		return (NULL);
	dest[data->heigh] = NULL;
	while (h < data->heigh)
	{
		dest[h] = ft_strdup(data->map[h]);
		h++;
	}
	return (dest);
}
