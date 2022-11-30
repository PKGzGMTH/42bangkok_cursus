/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:11:14 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/01 00:33:03 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

size_t	psloop(t_stack **a, t_stack **b, \
size_t (*function)(t_stack **, t_stack **), int count)
{
	long	i;

	i = 0;
	while (i++ < count)
		function(a, b);
	return (count);
}

void	dual_swap(t_stack **a, t_stack **b)
{
	if (*b && (*b)->next && (*b)->data < (*b)->next->data && \
	*a && (*a)->next && (*a)->data > (*a)->next->data)
		ss(a, b);
	else if (*b && (*b)->next && (*b)->data < (*b)->next->data)
		sb(a, b);
	else if (*a && (*a)->next && (*a)->data > (*a)->next->data)
		sa(a, b);
}
