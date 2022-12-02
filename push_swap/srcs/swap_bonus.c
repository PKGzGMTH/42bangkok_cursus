/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:51:58 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/02 11:55:08 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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
	return (1);
}
