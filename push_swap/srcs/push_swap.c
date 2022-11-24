/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:52:09 by ptippaya          #+#    #+#             */
/*   Updated: 2022/11/24 05:55:53 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	push_swap(t_stack **a, t_stack **b)
{
	size_t	remain;

	remain = 0;
	if (issorted(*a) && !length(*b))
		return ;
	if (!issorted(*a) && length(*a) > 3)
	{
		remain = push_med_2b(a, b);
		push_swap(a, b);
	}
	else if (!issorted(*a) && length(*a) <= 3)
		sort_a(a, b);
	if (issorted(*a) && *b && remain && remain > 4)
		push_back_range(a, b, remain);
	else if (issorted(*a) && *b && remain && remain <= 4)
		remain -= push_back(a, b, remain);
}
