/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:59:16 by brangrae          #+#    #+#             */
/*   Updated: 2022/04/10 18:36:45 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "push_swap.h"

static int	check_ins(char *ins, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(ins, "sa\n", 3) == 0)
		swap_a(stack_a, 'r');
	else if (ft_strncmp(ins, "sb\n", 3) == 0)
		swap_b(stack_b, 'r');
	else if (ft_strncmp(ins, "ss\n", 3) == 0)
		swap_ab(stack_a, stack_b, 'r');
	else if (ft_strncmp(ins, "pa\n", 3) == 0)
		push_a(stack_a, stack_b, 'r');
	else if (ft_strncmp(ins, "pb\n", 3) == 0)
		push_b(stack_a, stack_b, 'r');
	else if (ft_strncmp(ins, "ra\n", 3) == 0)
		rotate_a(stack_a, 'r');
	else if (ft_strncmp(ins, "rb\n", 3) == 0)
		rotate_b(stack_b, 'r');
	else if (ft_strncmp(ins, "rr\n", 3) == 0)
		rotate_ab(stack_a, stack_b, 'r');
	else if (ft_strncmp(ins, "rra\n", 4) == 0)
		rrotate_a(stack_a, 'r');
	else if (ft_strncmp(ins, "rrb\n", 4) == 0)
		rrotate_b(stack_b, 'r');
	else if (ft_strncmp(ins, "rrr\n", 4) == 0)
		rrotate_ab(stack_a, stack_b, 'r');
	else
		return (0);
	return (1);
}

int	ps_read(t_stack *stack_a, t_stack *stack_b)
{
	char	*ins;

	ins = get_next_line(0);
	while (ins != NULL)
	{
		if (!check_ins(ins, stack_a, stack_b))
			ft_error("Error\n");
		free(ins);
		ins = get_next_line(0);
	}
	if (issort(stack_a, 'a') && isfull(stack_a) && isempty(stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(ins);
	return (0);
}
