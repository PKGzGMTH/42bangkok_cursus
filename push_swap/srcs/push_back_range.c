/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:17:54 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/01 01:29:20 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static bool	is_morethan_med(t_stack *stack, int median)
{
	while (stack)
	{
		if (stack->data > median)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	push_back3(t_stack **a, t_stack **b)
{
	if ((*a)->data < (*a)->next->data && \
	(*a)->next->data < (*a)->next->next->data)
		return ;
	dual_swap(a, b);
	if ((*a)->next->data > (*a)->next->next->data)
	{
		pb(a, b);
		dual_swap(a, b);
		pa(a, b);
		dual_swap(a, b);
	}
}

static void	push_back4(t_stack **a, t_stack **b)
{
	if (issorted(*a))
		return ;
	psloop(a, b, pb, 2);
	dual_swap(a, b);
	if ((*b)->data > (*a)->data && (*b)->data > (*a)->next->data)
	{
		pb(a, b);
		sb(a, b);
		pa(a, b);
	}
	dual_swap(a, b);
	pa(a, b);
	dual_swap(a, b);
	pa(a, b);
	dual_swap(a, b);
}

static void	push_back_range2(t_stack **a, t_stack **b, \
size_t pushed, size_t remain)
{
	if (pushed > 4)
	{
		psloop(a, b, pb, pushed);
		push_back_range(a, b, pushed);
		pushed = 0;
	}
	else if (pushed == 4)
		push_back4(a, b);
	else if (pushed == 3)
		push_back3(a, b);
	else if (pushed == 2)
		dual_swap(a, b);
	if (remain > 4)
		push_back_range(a, b, remain);
	else if (remain > 0)
		push_back(a, b, remain);
}

void	push_back_range(t_stack **a, t_stack **b, size_t n)
{
	int		med;
	size_t	pushed;
	size_t	rotate;
	size_t	rotated;

	pushed = 0;
	rotate = 0;
	rotated = 0;
	med = get_med(*b, n);
	while (is_morethan_med(*b, med))
	{
		if ((*b)->data > med)
			pushed += pa(a, b);
		else
			rotated += rb(a, b);
	}
	while (rotate++ < rotated)
		rrb(a, b);
	push_back_range2(a, b, pushed, n - pushed);
}
