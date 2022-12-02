/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:16:51 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/02 11:54:53 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*cur;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		cur = *stack;
		while (cur && cur->next)
			cur = cur->next;
		cur->next = temp;
		temp->next = NULL;
	}
}

size_t	ra(t_stack **a, t_stack **b)
{
	(void)b;
	rotate(a);
	return (1);
}

size_t	rb(t_stack **a, t_stack **b)
{
	(void)a;
	rotate(b);
	return (1);
}

size_t	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	return (1);
}
