/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:13:41 by ptippaya          #+#    #+#             */
/*   Updated: 2022/03/29 20:46:10 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if ((8 < c && c < 14) || c == 32 || c == 27)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	answer;
	int	mul;

	mul = 1;
	answer = 0;
	while (*nptr && ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			mul *= -1;
		nptr++;
	}
	while ('0' <= *nptr && *nptr <= '9')
	{
		answer = (answer * 10) + (*nptr - '0');
		nptr++;
	}
	return (answer * mul);
}
