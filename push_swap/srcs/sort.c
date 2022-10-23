/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:52:14 by ptippaya          #+#    #+#             */
/*   Updated: 2022/10/23 23:10:44 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

/*
 * Broken now
 * Not working with first or last element
 */

static void	counter_firstlast(t_stack *stack, t_count *count)
{
	bool	find;
	t_stack	*cur;
	t_stack	*next;

	find = false;
	cur = stack;
	next = stack->next;
	while (cur && !find)
	{
		if (cur->data > next->data)
			find = true;
		(count->up)++;
		cur = cur->next;
		next = next->next;
		if (!next)
			next = stack;
	}
	while (cur)
	{
		(count->down)++;
		cur = cur->next;
	}
}

static void	counter_between(t_stack *stack, t_stack *target, t_count *count)
{
	bool	find;
	t_stack	*cur;
	t_stack	*next;

	find = false;
	cur = stack;
	next = stack->next;
	while (cur && !find)
	{
		if (cur->data < target->data && target->data < next->data)
			find = true;
		count->up++;
		next = next->next;
		if (!next)
			next = stack;
		cur = cur->next;
	}
	while (cur)
	{
		count->down++;
		cur = cur->next;
	}
}

static void	counter(t_stack *stack, t_stack *target, \
t_count *count, bool lastround)
{
	t_stack	*last;
	t_stack	*cur;
	t_stack	*max;
	t_stack	*min;

	last = stack;
	cur = stack;
	max = stack;
	min = stack;
	count->up = 0;
	count->down = 0;
	while (cur)
	{
		last = cur;
		if (last->data < min->data)
			min = last;
		if (last->data > max->data)
			max = last;
		cur = cur->next;
	}
	if (lastround || target->data < min->data || target->data > max->data)
		counter_firstlast(stack, count);
	else
		counter_between(stack, target, count);
}

/*
 * Not working now
 * Recoding is easier than debug and edit
 * to Me in future: just check all node of stack is sorted or not
 * 		if sorted node more than unsorted node just rotate Stack A
 * 		until find unsorted node and sort it!
 * 		I'm sleepy now, Goodbye!
 */

// static bool	check(t_stack *a, t_stack *b)
// {
// 	int	value;

// 	if (b)
// 		return (0);
// 	value = a->data;
// 	while (a)
// 		if (a->data < value)
// 			return (0);
// 	return (1);
// }

void	sort(t_stack **a, t_stack **b)
{
	bool			finish;
	t_count			count;
	unsigned int	i;

	finish = false;
	while (!finish)
	{
		if (*a && (*a)->next)
		{
			i = 0;
			finish = !*b;
			counter(*a, *b, &count, finish);
			if ((count.up || count.down) && count.up <= count.down)
				while (i++ < count.up)
					ra(a, b);
			else if (count.up > count.down)
				while (i++ < count.down)
					rra(a, b);
		}
		if (*b)
			pa(a, b);
	}
}
