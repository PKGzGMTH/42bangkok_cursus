/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:52:09 by ptippaya          #+#    #+#             */
/*   Updated: 2022/10/22 02:10:30 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static bool	push_swap_ll(t_stack **a, t_stack **b)
{
	if ((*a)->next->next->next)
	{
		pb(a, b);
		pb(a, b);
		pb(a, b);
		return (1);
	}
	else
		return (0);
}

static bool	push_swap_gg(t_stack **a, t_stack **b)
{
	if ((*a)->next->next->next)
	{
		pb(a, b);
		sa(a, b);
		if ((*b)->next)
			ra(a, b);
		pb(a, b);
		pb(a, b);
		rrb(a, b);
		return (1);
	}
	else
	{
		sa(a, b);
		rra(a, b);
		return (0);
	}
}

static bool	push_swap_lg(t_stack **a, t_stack **b)
{
	if ((*a)->next->next->next)
	{
		pb(a, b);
		sa(a, b);
		pb(a, b);
		if ((*b)->next->data > (*b)->data)
			sb(a, b);
		pb(a, b);
		return (1);
	}
	else
	{
		rra(a, b);
		if ((*a)->data > (*a)->next->data)
			sa(a, b);
		return (0);
	}
}

static bool	push_swap_gl(t_stack **a, t_stack **b)
{
	if ((*a)->next->next->next)
	{
		if ((*a)->data < (*a)->next->next->data)
			sa(a, b);
		pb(a, b);
		if ((*b)->next)
			rb(a, b);
		pb(a, b);
		pb(a, b);
		if ((*b)->data < (*b)->next->next->data)
			rrb(a, b);
		return (1);
	}
	else
	{
		if ((*a)->data < (*a)->next->next->data)
			sa(a, b);
		else
			ra(a, b);
		return (0);
	}
}

void	push_swap3(t_stack **a, t_stack **b)
{
	bool	flag;

	flag = 1;
	if (*a && (*a)->next && !(*a)->next->next && (*a)->data > (*a)->next->data)
		sa(a, b);
	while (flag && *a && (*a)->next && (*a)->next->next)
	{
		if ((*a)->data < (*a)->next->data && \
		(*a)->next->data < (*a)->next->next->data)
			flag = push_swap_ll(a, b);
		else if ((*a)->data > (*a)->next->data && \
		(*a)->next->data > (*a)->next->next->data)
			flag = push_swap_gg(a, b);
		else if ((*a)->data > (*a)->next->data && \
		(*a)->next->data < (*a)->next->next->data)
			flag = push_swap_gl(a, b);
		else
			flag = push_swap_lg(a, b);
	}
	sort(a, b);
}
