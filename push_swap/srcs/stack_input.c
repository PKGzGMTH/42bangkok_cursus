/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:33:21 by ptippaya          #+#    #+#             */
/*   Updated: 2022/10/28 20:48:03 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"
#include <stdio.h>

static bool	check_input(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 1;
	while (i < argc)
	{
		str = argv[i];
		while (*str)
		{
			if (!(('0' <= *str && *str <= '9') || *str == ' ' \
			|| ('\t' <= *str && *str <= '\r') || (*str == '-' && \
			('0' <= *(str + 1) && *(str + 1) <= '9'))))
				return (0);
			str++;
		}
		i++;
	}
	return (1);
}

static bool	stoi(t_stack **stack, char *str)
{
	long	n;
	int		mul;

	while (*str)
	{
		mul = 1;
		while (*str && !(('0' <= *str && *str <= '9') || *str == '-'))
			str++;
		if (*str == '-')
		{
			mul = -1;
			str++;
		}
		n = 0;
		while ('0' <= *str && *str <= '9')
			n = n * 10 + (*(str++) - '0');
		if (!(-2147483648 <= n * mul && n * mul <= 2147483647) \
		|| !push(stack, n * mul))
			return (0);
	}
	return (1);
}

bool	init_stack(t_stack **stack, int argc, char **argv)
{
	int	i;

	i = 1;
	(void)stack;
	if (!check_input(argc, argv))
		return (0);
	while (i < argc)
		if (!stoi(stack, argv[i++]))
			return (0);
	return (1);
}
