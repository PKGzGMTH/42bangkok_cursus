/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:28:17 by brangrae          #+#    #+#             */
/*   Updated: 2022/04/10 18:27:52 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_cal_1_sub1(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->arr[stack_b->top] > stack_b->arr[0]
		&& stack_b->arr[stack_b->top - 1] < stack_b->arr[0]
		&& stack_b->top >= 1)
	{
		rrotate_ab(stack_a, stack_b, 'w');
		swap_ab(stack_a, stack_b, 'w');
	}
	else
	{
		rrotate_a(stack_a, 'w');
		swap_a(stack_a, 'w');
	}
}

void	ps_cal_2_sub1(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->arr[stack_a->top] < stack_a->arr[1]
		&& stack_a->arr[1] < stack_a->arr[0])
		push_b(stack_a, stack_b, 'w');
	else if (dot_neartop(stack_a))
	{
		if (max_neartop(stack_b))
			rotate_ab(stack_a, stack_b, 'w');
		else
			rotate_a(stack_a, 'w');
	}
	else
	{
		if (!max_neartop(stack_b))
			rrotate_ab(stack_a, stack_b, 'w');
		else
			rrotate_a(stack_a, 'w');
	}
}

void	ps_cal_2_sub2(t_stack *stack_a, t_stack *stack_b)
{
	if (intmax(stack_b) > intmax(stack_a))
	{
		if (ismin(stack_a, stack_a->top))
			push_a(stack_a, stack_b, 'w');
		else if (min_neartop(stack_a))
			rotate_a(stack_a, 'w');
		else
			rrotate_a(stack_a, 'w');
	}
	else
	{
		if (intmax(stack_b) < stack_a->arr[stack_a->top]
			&& intmax(stack_b) > stack_a->arr[0])
			push_a(stack_a, stack_b, 'w');
		else if (spot_neartop(stack_a, intmax(stack_b)))
			rotate_a(stack_a, 'w');
		else
			rrotate_a(stack_a, 'w');
	}
}

void	ps_cal_2_sub3(t_stack *stack_a, t_stack *stack_b)
{
	if (max_neartop(stack_b))
	{
		if ((intmax(stack_b) > intmax(stack_a) && !ismin(stack_a, stack_a->top)
				&& min_neartop(stack_a)) || (intmax(stack_b) < intmax(stack_a)
				&& !(intmax(stack_b) < stack_a->arr[stack_a->top]
					&& intmax(stack_b) > stack_a->arr[0])
				&& spot_neartop(stack_a, intmax(stack_b))))
			rotate_ab(stack_a, stack_b, 'w');
		else
			rotate_b(stack_b, 'w');
	}
	else
	{
		if ((intmax(stack_b) > intmax(stack_a) && !ismin(stack_a, stack_a->top)
				&& !min_neartop(stack_a)) || (intmax(stack_b) < intmax(stack_a)
				&& !(intmax(stack_b) < stack_a->arr[stack_a->top]
					&& intmax(stack_b) > stack_a->arr[0])
				&& !spot_neartop(stack_a, intmax(stack_b))))
			rrotate_ab(stack_a, stack_b, 'w');
		else
			rrotate_b(stack_b, 'w');
	}
}

void	ps_cal_2_sub4(t_stack *stack_a, t_stack *stack_b)
{
	if (min_neartop(stack_a) && max_neartop(stack_b)
		&& !ismax(stack_b, stack_b->top) && stack_b->top >= 1)
		rotate_ab(stack_a, stack_b, 'w');
	else if (!min_neartop(stack_a) && !max_neartop(stack_b)
		&& !ismax(stack_b, stack_b->top) && stack_b->top >= 1)
		rrotate_ab(stack_a, stack_b, 'w');
	else if (min_neartop(stack_a))
		rotate_a(stack_a, 'w');
	else
		rrotate_a(stack_a, 'w');
}
