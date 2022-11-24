/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:47:53 by ptippaya          #+#    #+#             */
/*   Updated: 2022/11/24 03:06:12 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static void	revers_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		if (!(*stack)->next->next)
		{
			last = (*stack)->next;
			(*stack)->next = NULL;
			last->next = *stack;
			*stack = last;
		}
		else
		{
			temp = *stack;
			while (temp && temp->next && temp->next->next)
				temp = temp->next;
			last = temp->next;
			temp->next = NULL;
			last->next = *stack;
			*stack = last;
		}
	}
}

size_t	rra(t_stack **a, t_stack **b)
{
	(void)b;
	revers_rotate(a);
	write (1, "rra\n", 4);
	return (1);
}

size_t	rrb(t_stack **a, t_stack **b)
{
	(void)a;
	revers_rotate(b);
	write (1, "rrb\n", 4);
	return (1);
}

size_t	rrr(t_stack **a, t_stack **b)
{
	revers_rotate(a);
	revers_rotate(b);
	write (1, "rrr\n", 4);
	return (1);
}
