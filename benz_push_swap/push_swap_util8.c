/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:26:12 by brangrae          #+#    #+#             */
/*   Updated: 2022/04/10 18:28:34 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	max_pos(t_stack *stack)
{
	int	top;
	int	i;

	top = stack->top;
	i = -1;
	while (++i < stack->top)
		if (ismax(stack, i))
			break ;
	if (top - i < i + 1)
		return (top - i);
	return (i + 1);
}

int	spot_pos(t_stack *stack, int mark)
{
	int	top;
	int	bot;

	top = stack->top;
	bot = -1;
	while (--top > -1)
		if (mark < stack->arr[top] && mark > stack->arr[top + 1])
			break ;
	while (++bot < stack->top)
		if (mark < stack->arr[bot] && mark > stack->arr[bot + 1])
			break ;
	if (stack->top - top < bot + 1)
		return (stack->top - top);
	else if (stack->top - top > bot + 1)
		return (bot + 1);
	else if (mark > stack->arr[0] && mark < stack->arr[stack->top])
		return (0);
	return (-1);
}

void	ps_fillb(t_stack *stack_a, t_stack *stack_b, int floor, int med)
{
	while (intmin(stack_a) < med)
	{
		if (stack_a->arr[stack_a->top] < med)
			push_b(stack_a, stack_b, 'w');
		else
			rotate_a(stack_a, 'w');
	}
	while (intmin(stack_a) < floor)
	{
		if (stack_a->arr[stack_a->top] < floor)
			push_b(stack_a, stack_b, 'w');
		else
			rotate_a(stack_a, 'w');
	}
}

void	ps_filla(t_stack *stack_a, t_stack *stack_b, int floor, int med)
{
	while (intmax(stack_b) >= floor)
	{
		if (stack_b->arr[stack_b->top] > floor)
			push_a(stack_a, stack_b, 'w');
		else if (stack_b->arr[stack_b->top] == floor)
		{
			push_a(stack_a, stack_b, 'w');
			rotate_a(stack_a, 'w');
		}
		else if (f_neartop(stack_b, floor, 'b') || floor < med)
			rotate_b(stack_b, 'w');
		else
			rrotate_b(stack_b, 'w');
	}
}
