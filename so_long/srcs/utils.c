/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:21:00 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/15 21:00:45 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	safefree(void *content)
{
	if (content)
		free(content);
}

size_t	init_position(t_posotion *p, size_t x, size_t y)
{
	p->x = x;
	p->y = y;
	return (1);
}
