/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:12:02 by ptippaya          #+#    #+#             */
/*   Updated: 2022/11/24 05:55:25 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!init_stack(&a, argc, argv))
		write(2, "Error\n", 6);
	else
		push_swap(&a, &b);
	if (issorted(a))
		printf("it sorted!\n");
	print_stack(a, b, "final");
	freestack(&a);
	return (0);
}
