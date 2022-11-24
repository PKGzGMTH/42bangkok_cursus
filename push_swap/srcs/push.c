/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:25:00 by ptippaya          #+#    #+#             */
/*   Updated: 2022/11/24 03:06:11 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

size_t	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
	}
	write (1, "pa\n", 3);
	return (1);
}

size_t	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
	}
	write (1, "pb\n", 3);
	return (1);
}
