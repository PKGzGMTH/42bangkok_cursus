/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:04:37 by brangrae          #+#    #+#             */
/*   Updated: 2022/04/10 18:53:22 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	isfull(t_stack *stack)
{
	if (stack->top == stack->max - 1)
		return (1);
	else
		return (0);
}

int	isempty(t_stack *stack)
{
	if (stack->top == -1)
		return (1);
	else
		return (0);
}

void	push_a(t_stack *stack_a, t_stack *stack_b, int flag)
{
	if (!isfull(stack_a) && !isempty(stack_b))
	{
		stack_a->top += 1;
		stack_a->arr[stack_a->top] = stack_b->arr[stack_b->top];
		stack_b->top -= 1;
		if (flag == 'w')
			ft_putstr_fd("pa\n", 1);
	}
}

void	push_b(t_stack *stack_a, t_stack *stack_b, int flag)
{
	if (!isfull(stack_b) && !isempty(stack_a))
	{
		stack_b->top += 1;
		stack_b->arr[stack_b->top] = stack_a->arr[stack_a->top];
		stack_a->top -= 1;
		if (flag == 'w')
			ft_putstr_fd("pb\n", 1);
	}
}

t_stack	*ft_stack(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		ft_error("Error\n");
	stack->max = size;
	stack->top = -1;
	stack->arr = malloc(sizeof(int) * size);
	if (stack->arr == NULL)
		ft_error("Error\n");
	return (stack);
}
