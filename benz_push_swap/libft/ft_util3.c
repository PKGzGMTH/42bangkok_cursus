/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:02:31 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/24 22:46:38 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_und(unsigned long int un, int b)
{
	int	count;

	if (un == 0)
		return (1);
	count = 0;
	while (un > 0)
	{
		un /= b;
		count++;
	}
	return (count);
}

int	ft_putunb(unsigned long int un, int b, int c)
{
	char	*x;
	char	*x2;

	x = "0123456789abcdef";
	x2 = "0123456789ABCDEF";
	if (un >= (unsigned long int)b)
	{
		ft_putunb(un / b, b, c);
		ft_putunb(un % b, b, c);
	}
	else if (c == 'u')
		ft_putchar('0' + un);
	else if (c == 'x')
		ft_putchar(*(x + un));
	else if (c == 'X')
		ft_putchar(*(x2 + un));
	return (0);
}

int	ft_putunb_f(unsigned int unb, int flag, int digit)
{
	int					un_digit;
	unsigned long int	un;

	un = (unsigned long int)unb;
	un_digit = ft_und(un, 10);
	if (flag == 0 || flag == 1)
	{
		ft_putunb(un, 10, 'u');
		while (un_digit++ < digit)
			ft_putchar(' ');
	}
	else if (flag == 2 || (flag == 3 && (un != 0 || digit != 0)))
	{
		while (un_digit++ < digit)
			ft_putchar('0');
		ft_putunb(un, 10, 'u');
	}
	return (un_digit - 1);
}

int	ft_puthex_f(unsigned int hex, int x, int flag, int digit)
{
	int					hex_d;
	unsigned long int	hexl;

	hexl = (unsigned long int)hex;
	hex_d = ft_und(hexl, 16);
	if (flag == 0 || flag == 1)
	{
		ft_putunb(hexl, 16, x);
		while (hex_d++ < digit)
			ft_putchar(' ');
	}
	else if (flag == 2 || (flag == 3 && (hexl != 0 || digit != 0)))
	{
		while (hex_d++ < digit)
			ft_putchar('0');
		ft_putunb(hexl, 16, x);
	}
	else
		hex_d = ft_puthex_f4(hexl, x, flag, hex_d) + 1;
	return (hex_d - 1);
}

int	ft_puthex_f4(unsigned long int hexl, int x, int flag, int hex_d)
{
	if (flag == 4 & hexl != 0)
	{
		ft_putchar('0');
		ft_putchar(x);
		ft_putunb(hexl, 16, x);
		hex_d += 2;
	}
	else if (flag == 4 & hexl == 0)
		ft_putchar('0');
	return (hex_d);
}
