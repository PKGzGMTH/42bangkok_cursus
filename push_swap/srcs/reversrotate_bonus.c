/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversrotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:47:53 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/02 11:54:50 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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
	return (1);
}

size_t	rrb(t_stack **a, t_stack **b)
{
	(void)a;
	revers_rotate(b);
	return (1);
}

size_t	rrr(t_stack **a, t_stack **b)
{
	revers_rotate(a);
	revers_rotate(b);
	return (1);
}
