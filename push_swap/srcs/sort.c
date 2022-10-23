/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:52:14 by ptippaya          #+#    #+#             */
/*   Updated: 2022/10/23 13:40:46 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

/*
 * Broken now
 * Not working with first or last element
 */

static void	counter_firstlast(t_stack *stack, t_stack *last, t_count *count)
{
	t_stack	*first;

	first = stack;
	while (first && first->data > last->data)
	{
		(count->up)++;
		first = first->next;
		last = last->next;
		if (!last)
			last = stack;
	}
	while (first)
	{
		(count->down)++;
		first = first->next;
	}
}

static void	counter_between(t_stack *stack, t_stack *last, \
t_stack *target, t_count *count)
{
	t_stack	*cur;

	cur = stack;
	while (cur && !(cur->data < target->data && target->data < last->data) && \
	cur->data < last->data)
	{
		(count->up)++;
		cur = cur->next;
		last = last->next;
		if (!last)
			last = stack;
	}
	while (cur)
	{
		(count->down)++;
		cur = cur->next;
	}
}

static void	counter(t_stack *stack, t_stack *target, t_count *count)
{
	t_stack	*last;
	t_stack	*max;
	t_stack	*min;

	last = stack;
	max = stack;
	min = stack;
	count->up = 0;
	count->down = 0;
	while (last->next)
	{
		if (last->data < min->data)
			min = last;
		if (last->data > max->data)
			max = last;
		last = last->next;
	}
	if (target->data < min->data || target->data > max->data)
		counter_firstlast(stack, last, count);
	else
		counter_between(stack, last, target, count);
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
	t_count			count;
	unsigned int	i;

	while (*b)
	{
		if (*a && (*a)->next && (*a)->next->next)
		{
			i = 0;
			count.up = 0;
			count.down = 0;
			counter(*a, *b, *counter);
			printf("%u %u\n", count.up, count.down);
			if ((count.up || count.down) && count.up <= count.down)
				while (i++ < count.up)
					ra(a, b);
			else if (count.up > count.down)
				while (i++ < count.down)
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
