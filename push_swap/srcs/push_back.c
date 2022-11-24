/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:29:51 by ptippaya          #+#    #+#             */
/*   Updated: 2022/11/24 05:54:50 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static void	push_back2(t_stack **a, t_stack **b)
{
	dual_swap(a, b);
	if (*b && (*b)->next)
		psloop(a, b, pa, 2);
}

static void	push_back3(t_stack **a, t_stack **b)
{
	dual_swap(a, b);
	pa(a, b);
	dual_swap(a, b);
	pa(a, b);
	dual_swap(a, b);
	pa(a, b);
}

static void	push_back4(t_stack **a, t_stack **b)
{
	psloop(a, b, pa, 2);
	dual_swap(a, b);
	pa(a, b);
	dual_swap(a, b);
	pb(a, b);
	dual_swap(a, b);
	pa(a, b);
	dual_swap(a, b);
	pa(a, b);
	dual_swap(a, b);
}

size_t	push_back(t_stack **a, t_stack **b, size_t n)
{
	if (n == 1)
		pa(a, b);
	else if (n == 2)
		push_back2(a, b);
	else if (n == 3)
		push_back3(a, b);
	else if (n == 4)
		push_back4(a, b);
	return (n);
}
