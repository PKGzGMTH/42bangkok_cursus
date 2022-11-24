/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:36:38 by ptippaya          #+#    #+#             */
/*   Updated: 2022/11/23 23:05:09 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static void	sort_a_3(t_stack **a, t_stack **b)
{
	if (length(*a) == 3 && (*a)->data > (*a)->next->data && \
	(*a)->next->data > (*a)->next->next->data)
	{
		dual_swap(a, b);
		rra(a, b);
	}
	else if (length(*a) == 3 && (*a)->data > (*a)->next->data && \
	(*a)->next->data < (*a)->next->next->data)
	{
		if ((*a)->data > (*a)->next->next->data)
			ra(a, b);
		dual_swap(a, b);
	}
	else if (length(*a) == 3 && (*a)->data < (*a)->next->data && \
	(*a)->next->data > (*a)->next->next->data)
	{
		rra(a, b);
		dual_swap(a, b);
	}
}

void	sort_a(t_stack **a, t_stack **b)
{
	if (!issorted(*a) && length(*a) == 3)
		sort_a_3(a, b);
	if (!issorted(*a) && length(*a) == 2)
		dual_swap(a, b);
}
