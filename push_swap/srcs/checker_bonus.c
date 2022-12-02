/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:20:36 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/02 12:38:30 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"
#include <ctype.h>

static bool	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (0);
	return (1);
}

static char	*input(char *buff)
{
	size_t	i;

	i = 0;
	buff[0] = 0;
	while (read(0, buff + i++, 1) && buff[i - 1] != '\n' && \
	(buff[i - 1] == 's' || buff[i - 1] == 'p' || buff[i - 1] == 'r' || \
	buff[i - 1] == 'a' || buff[i - 1] == 'b'))
		buff[i] = '\0';
	if (buff[i - 1] == '\n')
		buff[i - 1] = '\0';
	return (buff);
}

static bool	push_swap(t_stack **a, t_stack **b, char *s)
{
	if (ft_strcmp(s, "sa"))
		sa(a, b);
	else if (ft_strcmp(s, "sb"))
		sb(a, b);
	else if (ft_strcmp(s, "ss"))
		ss(a, b);
	else if (ft_strcmp(s, "pa"))
		pa(a, b);
	else if (ft_strcmp(s, "pb"))
		pb(a, b);
	else if (ft_strcmp(s, "ra"))
		ra(a, b);
	else if (ft_strcmp(s, "rb"))
		rb(a, b);
	else if (ft_strcmp(s, "rr"))
		rr(a, b);
	else if (ft_strcmp(s, "rra"))
		rra(a, b);
	else if (ft_strcmp(s, "rrb"))
		rrb(a, b);
	else if (ft_strcmp(s, "rrr"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	checker(t_stack **a, t_stack **b)
{
	char	mem[5];
	char	*buff;

	buff = input(mem);
	if (!*buff)
		return (0);
	while (*buff)
	{
		if (!push_swap(a, b, buff))
			return (0);
		buff = input(mem);
	}
	if (issorted(*a) && !*b)
		return (1);
	else
		return (2);
}
