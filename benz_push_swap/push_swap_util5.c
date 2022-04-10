/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:10:25 by brangrae          #+#    #+#             */
/*   Updated: 2022/04/10 19:00:49 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ismax(t_stack *stack, int pos)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < stack->top + 1)
		if (stack->arr[i++] < stack->arr[pos])
			count++;
	if (count == stack->top)
		return (1);
	return (0);
}

int	ismin(t_stack *stack, int pos)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < stack->top + 1)
		if (stack->arr[i++] > stack->arr[pos])
			count++;
	if (count == stack->top)
		return (1);
	return (0);
}

int	min_neartop(t_stack *stack)
{
	int	top;
	int	i;

	top = stack->top;
	i = -1;
	while (++i < stack->top)
		if (ismin(stack, i))
			break ;
	if (top - i < i + 1)
		return (1);
	return (0);
}

int	max_neartop(t_stack *stack)
{
	int	top;
	int	i;

	top = stack->top;
	i = -1;
	while (++i < stack->top)
		if (ismax(stack, i))
			break ;
	if (top - i < i + 1)
		return (1);
	return (0);
}

void	ft_release(t_stack *stack)
{
	free(stack);
	free(stack->arr);
}
