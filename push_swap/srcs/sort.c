/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:52:14 by ptippaya          #+#    #+#             */
/*   Updated: 2022/10/22 03:11:10 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static void	counter(t_stack *stack, t_stack *target, \
			unsigned int *up, unsigned int *down)
{
	t_stack			*cur;

	cur = stack;
	while (cur && target->data < cur->data)
	{
		(*up)++;
		cur = cur->next;
	}
	while (cur)
	{
		(*down)++;
		cur = cur->next;
	}
}

/*
 * Not working now
 * Recoding is easier than debug and edit
 * to Me in future: just check all node of stack is sorted or not
 * 		if sorted node more than unsorted node just rotate Stack A
 * 		until find unsorted node and sort it!
 * 		I'm sleepy now, Goodbye!
 */

void	sort(t_stack **a, t_stack **b)
{
	unsigned int	up;
	unsigned int	down;
	unsigned int	count;

	while (*b)
	{
		up = 0;
		down = 0;
		count = 0;
		counter(*a, *b, &up, &down);
		if (up < down)
			while (count++ < up)
				ra(a, b);
		else
			while (count++ < down)
				rra(a, b);
		pa(a, b);
	}
	count = 0;
	counter(*a , *a, &up, &down);
	if (up < down)
		while (count++ < up)
			ra(a, b);
	else
		while (count++ < down)
			rra(a, b);
}
