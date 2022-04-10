/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:18:36 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/25 00:24:49 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbd(long int nb)
{
	int	count;

	if (nb == 0)
		return (1);
	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static void	ft_putnbr(long int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int	ft_putnbr_f(int nbr, int flag, int digit)
{
	int			nb_digit;
	long int	nb;

	nb = (long int)nbr;
	nb_digit = ft_nbd(nb);
	if (flag == 0 || flag == 1)
	{
		ft_putnbr(nb);
		while (nb_digit++ < digit)
			ft_putchar(' ');
	}
	else if (flag == 2)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		while (nb_digit++ < digit)
			ft_putchar('0');
		ft_putnbr(nb);
	}
	else
		nb_digit = ft_putnbr_f2(nbr, flag, digit, nb_digit) + 1;
	return (nb_digit - 1);
}

int	ft_putnbr_f2(int nbr, int flag, int digit, int nbd)
{
	long int	nb;
	int			numf;

	nb = (long int)nbr;
	numf = 0;
	if (flag == 3 && (nb != 0 || digit != 0))
	{
		if (nb < 0)
		{
			nbd--;
			numf += ft_putchar('-');
			nb *= -1;
		}
		while (nbd++ < digit)
			ft_putchar('0');
		ft_putnbr(nb);
	}
	else if (flag == 5 || flag == 6)
		nbd = ft_putnbr_f56(nb, flag, nbd) + 1;
	return (nbd - 1 + numf);
}

int	ft_putnbr_f56(long int nb, int flag, int nbd)
{
	if (nb >= 0 && flag == 5)
	{
		ft_putchar(' ');
		nbd++;
	}
	else if (nb >= 0 && flag == 6)
	{
		ft_putchar('+');
		nbd++;
	}
	ft_putnbr(nb);
	return (nbd);
}
