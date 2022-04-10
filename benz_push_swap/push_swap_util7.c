/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:21:45 by brangrae          #+#    #+#             */
/*   Updated: 2022/04/10 09:51:34 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	iscycle(t_stack *stack)
{
	int	top;
	int	i;

	top = stack->top + 1;
	i = -1;
	while (++i < stack->top)
		if (stack->arr[i] > stack->arr[i + 1]
			|| (ismin(stack, i) && ismax(stack, i + 1)))
			top--;
	if (stack->arr[i] > stack->arr[0]
		|| (ismin(stack, i) && ismax(stack, 0)))
		top--;
	if (top == 0)
		return (1);
	return (0);
}

int	dot_neartop(t_stack *stack)
{
	int	top;
	int	bot;

	top = stack->top;
	bot = -1;
	while (--top > -1)
		if (stack->arr[top] < stack->arr[top + 1] && !ismin(stack, top))
			break ;
	if (ismin(stack, stack->top) || stack->arr[stack->top] > stack->arr[0])
		while (++bot < stack->top - 1)
			if (stack->arr[bot] < stack->arr[bot + 1]
				&& !ismin(stack, bot))
				break ;
	if (stack->top - top <= bot + 2)
		return (1);
	return (0);
}

int	spot_neartop(t_stack *stack, int mark)
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
		return (1);
	return (0);
}

int	range(int max)
{
	int	range;

	if (max <= 20)
		range = 20;
	if (max > 20 && max <= 200)
		range = max / (max / 20);
	if (max > 200)
		range = max / (max / 50);
	return (range);
}
