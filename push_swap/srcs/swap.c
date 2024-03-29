/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:51:58 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/01 19:09:29 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	sa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	(void)b;
	if (*a && (*a)->next)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = (*a)->next;
		(*a)->next = temp;
	}
	write(1, "sa\n", 3);
	return (1);
}

size_t	sb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	(void)a;
	if (*b && (*b)->next)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = (*b)->next;
		(*b)->next = temp;
	}
	write(1, "sb\n", 3);
	return (1);
}

size_t	ss(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a && (*a)->next)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = (*a)->next;
		(*a)->next = temp;
	}
	if (*b && (*b)->next)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = (*b)->next;
		(*b)->next = temp;
	}
	write(1, "ss\n", 3);
	return (1);
}
