/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:33:21 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/02 12:59:15 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static bool	isint(char *s)
{
	while (*s)
	{
		if ('0' <= *s && *s <= '9')
			return (1);
		s++;
	}
	return (0);
}

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

	if (!isint(str))
		return (0);
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
		if (!(-2147483648 <= n * mul && n * mul <= 2147483647))
			return (0);
		if ('0' <= *(str - 1) && *(str - 1) <= '9' && !push(stack, n * mul))
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
