/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:33:21 by ptippaya          #+#    #+#             */
/*   Updated: 2022/10/21 14:59:29 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"
#include <stdio.h>

/*
 * Function:	check_input
 * ------------------------
 *	Check each argument is number (+, -) or space.
 *
 *	returns:	1 (Argument are integer only)
 *				0 (Argument aren't integer only)
 */

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

/*
 * Function:	stoi
 * -----------------
 *	Convert each number in string to integer and push in back of stack.
 *	this function can push integer to stack more than one time.
 *
 *	returns:	1 (Convert argument to integer and push successful)
 *				0 (Argument are not integer or push function error)
 */

static bool	stoi(t_stack **stack, char *str)
{
	int	n;
	int	mul;

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
		{
			if (n * 10 + (*str - '0') < n && mul == 1)
				return (0);
			n = n * 10 + (*(str++) - '0');
			if (!('0' <= *str && *str <= '9') && !push(stack, n * mul))
				return (0);
		}
	}
	return (1);
}

/*
 * Function:	init_stack
 * -----------------------
 *	Initial all number in string to stack linked-list
 *
 *	returns:	 1 (Successful)
 *				 0 (Error)
 */

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
	init_index(*stack);
	return (1);
}
