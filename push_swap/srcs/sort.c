/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:52:14 by ptippaya          #+#    #+#             */
/*   Updated: 2022/10/22 21:19:20 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

/*
 * Broken now
 * Not working with first or last element
 */

static void	counter(t_stack *stack, t_stack *target, \
			unsigned int *up, unsigned int *down)
{
	t_stack	*cur;
	t_stack	*last;

	cur = stack;
	last = stack;
	(*up) = 0;
	(*down) = 0;
	while (last->next)
		last = last->next;
	while (cur && !(cur->data > target->data && target->data > last->data))
	{
		(*up)++;
		cur = cur->next;
		if (cur->data > last->data)
			break ;
		last = last->next;
		if (!last)
			last = stack;
	}
	while (cur)
	{
		cur = cur->next;
		(*down)++;
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
		if (*a && (*a)->next && (*a)->next->next)
		{
			up = 0;
			down = 0;
			count = 0;
			counter(*a, *b, &up, &down);
			printf("%u %u\n", up, down);
			if ((up || down) && up <= down)
				while (count++ < up)
					ra(a, b);
			else if (up > down)
				while (count++ < down)
					rra(a, b);
			pa(a, b);
		}
		else
			pa(a, b);
		print_stack(*a, *b);
	}
	// count = 0;
	// counter(*a , *a, &up, &down);
	// if (up < down)
	// 	while (count++ < up)
	// 		ra(a, b);
	// else
	// 	while (count++ < down)
	// 		rra(a, b);
}
