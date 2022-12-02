/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:38:47 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/01 19:08:43 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	is_lessthan_med(t_stack *stack, int median)
{
	while (stack)
	{
		if (stack->data < median)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	count_down_median(t_stack *stack, int median, \
t_count *count, t_count *find)
{
	while (stack)
	{
		find->down = 0;
		count->down = 0;
		while (stack && stack->data >= median)
		{
			stack = stack->next;
		}
		while (stack && stack->data < median)
		{
			find->down++;
			count->down++;
			stack = stack->next;
		}
		while (stack && stack->data >= median)
		{
			count->down++;
			stack = stack->next;
		}
	}
}

static void	count_up_median(t_stack *stack, int median, \
t_count *count, t_count *find)
{
	find->up = 0;
	find->down = 0;
	count->up = 0;
	count->down = 0;
	while (stack && stack->data >= median)
	{
		count->up++;
		stack = stack->next;
	}
	while (stack && stack->data < median)
	{
		find->up++;
		stack = stack->next;
	}
}

int	get_med(t_stack *stack, size_t n)
{
	int		med;
	int		*arr;
	size_t	i;
	t_stack	*h;
	t_stack	*temp;

	i = 0;
	h = stack;
	while (i++ < n - 1 && h)
		h = h->next;
	temp = h->next;
	h->next = NULL;
	h = stack;
	arr = sorted_array(h);
	med = arr[n / 2];
	free (arr);
	i = 0;
	while (i++ < n - 1 && h)
		h = h->next;
	h->next = temp;
	return (med);
}

size_t	push_med_2b(t_stack **a, t_stack **b)
{
	int		median;
	size_t	pcount;
	t_count	find;
	t_count	count;

	pcount = 0;
	median = get_med(*a, length(*a));
	while (!is_lessthan_med(*a, median))
	{
		count_up_median(*a, median, &count, &find);
		count_down_median(*a, median, &count, &find);
		if ((count.up && count.down && count.up == count.down && find.down && \
		find.up < find.down) || (count.up > count.down && find.down))
		{
			psloop(a, b, rra, count.down);
			pcount += psloop(a, b, pb, find.down);
		}
		else
		{
			psloop(a, b, ra, count.up);
			pcount += psloop(a, b, pb, find.up);
		}
	}
	return (pcount);
}
