/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:26:30 by brangrae          #+#    #+#             */
/*   Updated: 2022/04/04 10:23:43 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	intmin(t_stack *stack)
{
	int	i;
	int	j;
	int	min;
	int	*stack_t;

	stack_t = copyint(stack);
	i = 0;
	while (i < stack->top)
	{
		min = i;
		j = i;
		while (++j < stack->top + 1)
			if (stack_t[j] < stack_t[min])
				min = j;
		ft_swap(&stack_t[min], &stack_t[i++]);
	}
	min = stack_t[0];
	free(stack_t);
	return (min);
}

int	intmax(t_stack *stack)
{
	int	i;
	int	j;
	int	max;
	int	*stack_t;

	stack_t = copyint(stack);
	i = 0;
	while (i < stack->top)
	{
		max = i;
		j = i;
		while (++j < stack->top + 1)
			if (stack_t[j] < stack_t[max])
				max = j;
		ft_swap(&stack_t[max], &stack_t[i++]);
	}
	max = stack_t[stack->top];
	free(stack_t);
	return (max);
}

int	f_neartop(t_stack *stack, int floor, int type)
{
	int	top;
	int	bot;

	top = stack->top;
	bot = -1;
	while (top > 0 && type == 'a')
		if (stack->arr[--top] < floor)
			break ;
	while (bot < stack->top - 1 && type == 'a')
		if (stack->arr[++bot] < floor)
			break ;
	while (top > 0 && type == 'b')
		if (stack->arr[--top] >= floor)
			break ;
	while (bot < stack->top - 1 && type == 'b')
		if (stack->arr[++bot] >= floor)
			break ;
	if (stack->top - top < bot + 1)
		return (1);
	return (0);
}

t_stack	*ft_sort(t_stack *stack)
{
	t_stack	*stack_c;
	int		i;

	stack_c = ft_stack(stack->max);
	i = 0;
	while (i < stack->max)
	{
		stack_c->arr[i] = stack->arr[i];
		stack_c->top += 1;
		i++;
	}
	return (stack_c);
}
