/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:52:48 by brangrae          #+#    #+#             */
/*   Updated: 2022/04/10 16:05:11 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	ft_rrotate(t_stack *stack)
{
	int	tmp;
	int	i;

	tmp = stack->arr[0];
	i = 0;
	while (i < stack->top)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->top] = tmp;
}

void	rrotate_a(t_stack *stack_a, int flag)
{
	ft_rrotate(stack_a);
	if (flag == 'w')
		ft_putstr_fd("rra\n", 1);
}

void	rrotate_b(t_stack *stack_b, int flag)
{
	ft_rrotate(stack_b);
	if (flag == 'w')
		ft_putstr_fd("rrb\n", 1);
}

void	rrotate_ab(t_stack *stack_a, t_stack *stack_b, int flag)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
	if (flag == 'w')
		ft_putstr_fd("rrr\n", 1);
}

int	issort(t_stack *stack, int type)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < stack->top && type == 'a')
	{
		if (stack->arr[i] > stack->arr[i + 1])
			count++;
		i++;
	}
	while (i < stack->top && type == 'b')
	{
		if (stack->arr[i] < stack->arr[i + 1])
			count++;
		i++;
	}
	if (count == stack->top)
		return (1);
	return (0);
}
