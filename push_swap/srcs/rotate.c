/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:16:51 by ptippaya          #+#    #+#             */
/*   Updated: 2022/10/20 20:52:14 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

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

void	ra(t_stack **a, t_stack **b)
{
	(void)b;
	rotate(a);
	write (1, "ra\n", 3);
}

void	rb(t_stack **a, t_stack **b)
{
	(void)a;
	rotate(b);
	write (1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write (1, "rr\n", 3);
}
