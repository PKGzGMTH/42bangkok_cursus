/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:16:51 by ptippaya          #+#    #+#             */
/*   Updated: 2022/11/24 03:06:30 by ptippaya         ###   ########.fr       */
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

size_t	ra(t_stack **a, t_stack **b)
{
	(void)b;
	rotate(a);
	write (1, "ra\n", 3);
	return (1);
}

size_t	rb(t_stack **a, t_stack **b)
{
	(void)a;
	rotate(b);
	write (1, "rb\n", 3);
	return (1);
}

size_t	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write (1, "rr\n", 3);
	return (1);
}
