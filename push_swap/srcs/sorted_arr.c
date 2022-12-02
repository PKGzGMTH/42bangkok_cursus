/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:59:33 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/01 19:09:15 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_next_min(t_stack *stack, long lastmin)
{
	long		min;

	min = 2147483648;
	while (stack)
	{
		if ((lastmin < stack->data && stack->data <= min) || stack->data == min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	*sorted_array(t_stack *stack)
{
	int		*arr;
	size_t	i;
	size_t	len;

	i = 1;
	len = length(stack);
	arr = (int *) malloc ((sizeof(int) * len) + 1);
	if (!arr)
		return (0);
	arr[len] = 0;
	arr[0] = get_next_min(stack, -2147483649);
	while (i < len)
	{
		arr[i] = get_next_min(stack, (long) arr[i - 1]);
		i++;
	}
	return (arr);
}
