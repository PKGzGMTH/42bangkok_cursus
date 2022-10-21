/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:54:33 by ptippaya          #+#    #+#             */
/*   Updated: 2022/10/22 01:35:49 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"
#include <stdio.h>

static void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d[%d] -> ", stack->data, stack->index);
		stack = stack->next;
	}
	printf ("NULL\n");
}


int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!init_stack(&a, argc, argv))
	{
		freestack(&a);
		write(2, "Error\n", 6);
		return (0);
	}
	print_stack(a);
	push_swap3(&a, &b);
	print_stack(a);
	print_stack(b);
	return (0);
}
