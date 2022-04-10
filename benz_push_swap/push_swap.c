/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:30:07 by brangrae          #+#    #+#             */
/*   Updated: 2022/04/10 19:01:36 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

static int	ft_isnum(const char *str)
{
	size_t	i;
	int		least;

	i = 0;
	least = 0;
	if (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) > 0)
	{
		least++;
		i++;
	}
	if (i == ft_strlen(str) && least > 0)
		return (1);
	return (0);
}

static long long	ft_atoll(const char *str)
{
	int			i;
	int			sign;
	long long	value;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	value = 0;
	while (ft_isdigit(str[i]) > 0)
	{
		value = (value * 10) + (str[i] - '0');
		i++;
	}
	return (value * sign);
}

static int	arg_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
		if (ft_isnum(argv[i++]) == 0)
			return (-1);
	i = 0;
	while (++i < argc)
		if (ft_atoll(argv[i]) < INT_MIN || ft_atoll(argv[i]) > INT_MAX)
			return (-1);
	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
			if (ft_atoll(argv[i]) == ft_atoll(argv[j++]))
				return (-1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (argc > 1)
	{
		if (arg_error(argc, argv) == -1)
			ft_error("Error\n");
		stack_a = ft_stack(argc - 1);
		stack_b = ft_stack(argc - 1);
		i = 0;
		while (i < argc - 1)
		{
			stack_a->arr[i] = ft_atoi(argv[argc - i - 1]);
			stack_a->top += 1;
			i++;
		}
		ps_solve(stack_a, stack_b);
		ft_release(stack_a);
		ft_release(stack_b);
	}
	return (0);
}
