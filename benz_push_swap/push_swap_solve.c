/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:21:30 by brangrae          #+#    #+#             */
/*   Updated: 2022/04/10 19:06:53 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	ps_cal_3(t_stack *stack_a, t_stack *stack_b)
{
	if (ismax(stack_b, stack_b->top) && issort(stack_a, 'a'))
		push_a(stack_a, stack_b, 'w');
	else if (stack_b->arr[stack_b->top] > stack_b->arr[0]
		&& stack_b->arr[stack_b->top - 1] < stack_b->arr[0]
		&& stack_b->top >= 1)
	{
		rrotate_b(stack_b, 'w');
		swap_b(stack_b, 'w');
	}
	else if (stack_b->arr[stack_b->top] < stack_b->arr[stack_b->top - 1]
		&& stack_b->arr[stack_b->top] > stack_b->arr[stack_b->top - 2]
		&& stack_b->top >= 1)
		swap_b(stack_b, 'w');
	else
	{
		if (max_neartop(stack_b))
			rotate_b(stack_b, 'w');
		else
			rrotate_b(stack_b, 'w');
	}
}

static void	ps_cal_2(t_stack *stack_a, t_stack *stack_b)
{
	if (!iscycle(stack_a))
		ps_cal_2_sub1(stack_a, stack_b);
	else if (iscycle(stack_a) && intmax(stack_b) > intmin(stack_a)
		&& !isempty(stack_b))
	{
		if (ismax(stack_b, stack_b->top))
			ps_cal_2_sub2(stack_a, stack_b);
		else if (spot_pos(stack_a, stack_b->arr[stack_b->top]) == 0)
			push_a(stack_a, stack_b, 'w');
		else if (spot_pos(stack_a, stack_b->arr[stack_b->top]) > 0
			&& spot_pos(stack_a, stack_b->arr[stack_b->top]) < max_pos(stack_b))
		{
			if (spot_neartop(stack_a, stack_b->arr[stack_b->top]))
				rotate_a(stack_a, 'w');
			else
				rrotate_a(stack_a, 'w');
		}
		else
			ps_cal_2_sub3(stack_a, stack_b);
	}
	else if (!ismin(stack_a, stack_a->top) && !issort(stack_a, 'a'))
		ps_cal_2_sub4(stack_a, stack_b);
	else
		ps_cal_3(stack_a, stack_b);
}

static void	ps_cal_1(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->arr[stack_a->top] < stack_a->arr[0]
		&& stack_a->arr[0] < stack_a->arr[stack_a->top - 1] && stack_a->top < 5)
		ps_cal_1_sub1(stack_a, stack_b);
	else if (stack_a->arr[stack_a->top] > stack_a->arr[stack_a->top - 1]
		&& (stack_a->arr[stack_a->top] < stack_a->arr[stack_a->top - 2]
			|| (stack_a->top < 3 && !iscycle(stack_a))))
	{
		if (stack_b->arr[stack_b->top] < stack_b->arr[stack_b->top - 1]
			&& stack_b->arr[stack_b->top] > stack_b->arr[stack_b->top - 2]
			&& stack_b->top >= 1)
			swap_ab(stack_a, stack_b, 'w');
		else
			swap_a(stack_a, 'w');
	}
	else if (stack_a->arr[stack_a->top] > stack_a->arr[stack_a->top - 1]
		&& stack_a->arr[stack_a->top] > stack_a->arr[stack_a->top - 2]
		&& !(ismax(stack_a, stack_a->top) && ismin(stack_a, stack_a->top - 1)))
		push_b(stack_a, stack_b, 'w');
	else
		ps_cal_2(stack_a, stack_b);
}

int	ps_solve(t_stack *stack_a, t_stack *stack_b)
{
	int		c;
	int		i;
	int		rng;
	int		med;
	t_stack	*stack_c;

	stack_c = ft_sort(stack_a);
	rng = range(stack_c->max);
	med = fl(stack_c, 1, stack_c->max / 2);
	c = (stack_c->max - 1) / rng;
	i = 0;
	while (stack_a->max > 1)
	{
		if (issort(stack_a, 'a') && isfull(stack_a) && isempty(stack_b))
			break ;
		else if (isfull(stack_a) && i < c)
			ps_fillb(stack_a, stack_b, fl(stack_c, ++i, rng), med);
		else if (issort(stack_a, 'a') && stack_a->top == (rng * i) - 1
			&& intmin(stack_a) == fl(stack_c, i, rng) && i < c)
			ps_filla(stack_a, stack_b, fl(stack_c, ++i, rng), med);
		else
			ps_cal_1(stack_a, stack_b);
	}
	ft_release(stack_c);
	return (0);
}
