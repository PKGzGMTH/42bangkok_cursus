/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:12:02 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/02 11:48:20 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	main(int argc, char **argv)
{
	int		check;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!init_stack(&a, argc, argv))
		write(2, "Error\n", 6);
	else
	{
		check = checker(&a, &b);
		if (check == 0)
			write(2, "Error\n", 6);
		if (check == 1)
			write(2, "OK\n", 3);
		if (check == 2)
			write(2, "KO\n", 3);
	}
	freestack(&a);
	freestack(&b);
	return (0);
}
