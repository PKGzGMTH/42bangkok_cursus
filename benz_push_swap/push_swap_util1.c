/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:37:10 by brangrae          #+#    #+#             */
/*   Updated: 2022/04/10 16:01:27 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	x;
	int	y;

	x = *a;
	y = *b;
	*a = y;
	*b = x;
}

void	swap_a(t_stack *stack_a, int flag)
{
	ft_swap(&stack_a->arr[stack_a->top], &stack_a->arr[stack_a->top - 1]);
	if (flag == 'w')
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack *stack_b, int flag)
{
	ft_swap(&stack_b->arr[stack_b->top], &stack_b->arr[stack_b->top - 1]);
	if (flag == 'w')
		ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b, int flag)
{
	ft_swap(&stack_a->arr[stack_a->top], &stack_a->arr[stack_a->top - 1]);
	ft_swap(&stack_b->arr[stack_b->top], &stack_b->arr[stack_b->top - 1]);
	if (flag == 'w')
		ft_putstr_fd("ss\n", 1);
}

int	fl(t_stack *stack, int m, int range)
{
	int	i;
	int	j;
	int	min;
	int	value;
	int	*stack_t;

	stack_t = copyint(stack);
	i = 0;
	while (i < stack->max - 1)
	{
		min = i;
		j = i;
		while (++j < stack->max)
			if (stack_t[j] < stack_t[min])
				min = j;
		ft_swap(&stack_t[min], &stack_t[i++]);
	}
	value = stack_t[stack->max - (range * m)];
	free(stack_t);
	return (value);
}
