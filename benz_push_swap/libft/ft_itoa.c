/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:11:34 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/19 08:27:26 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0 && n != -2147483648)
	{
		i += 1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_put_itoa(char *nb, int n, int i)
{
	while (i >= 0 && n != 0)
	{
		if (n == -2147483648)
		{
			nb[0] = '-';
			nb[1] = '2';
			n = 147483648;
		}
		if (n < 0 && n != -2147483648)
		{
			nb[0] = '-';
			n *= -1;
		}
		if (n > 0)
		{
			nb[i--] = (n % 10) + '0';
			n /= 10;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		digit;
	int		i;

	digit = ft_digit(n);
	nb = malloc(sizeof(*nb) * (digit + 1));
	if (nb == NULL)
		return (0);
	i = digit - 1;
	if (n == 0)
		nb[0] = '0';
	else
		ft_put_itoa(nb, n, i);
	nb[digit] = '\0';
	return (nb);
}
