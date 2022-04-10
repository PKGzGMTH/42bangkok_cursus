/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:26:35 by brangrae          #+#    #+#             */
/*   Updated: 2022/04/10 16:04:13 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	ft_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	tmp = stack->arr[stack->top];
	i = 0;
	while (i < stack->top)
	{
		stack->arr[stack->top - i] = stack->arr[stack->top - i - 1];
		i++;
	}
	stack->arr[0] = tmp;
}

void	rotate_a(t_stack *stack_a, int flag)
{
	ft_rotate(stack_a);
	if (flag == 'w')
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack *stack_b, int flag)
{
	ft_rotate(stack_b);
	if (flag == 'w')
		ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_stack *stack_a, t_stack *stack_b, int flag)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (flag == 'w')
		ft_putstr_fd("rr\n", 1);
}

int	*copyint(t_stack *stack)
{
	int	*stack_t;
	int	i;

	stack_t = malloc(sizeof(int) * stack->max);
	if (stack_t == NULL)
		ft_error("Error\n");
	i = 0;
	while (i < stack->max)
	{
		stack_t[i] = stack->arr[i];
		i++;
	}
	return (stack_t);
}
