/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:36:16 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/24 22:42:48 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	write(1, &uc, 1);
	return (1);
}

int	ft_putchar_f(int c, int flag, int digit)
{
	int	numf;

	if (flag == 0 || flag == 1)
		numf = ft_putchar(c);
	if (flag == 1 && digit > 1)
		while (digit-- > 1)
			numf += ft_putchar(' ');
	return (numf);
}

int	ft_putstr_f(const char *str, int flag, int digit)
{
	int	numf;

	numf = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		numf += 6;
		digit -= 6;
	}
	else if (flag == 0 || flag == 1)
	{
		while (*str)
		{
			numf += ft_putchar(*str++);
			digit--;
		}
	}
	if (flag == 1 && digit > 0)
		while (digit-- > 0)
			numf += ft_putchar(' ');
	else if (flag == 3 && digit > 0)
		while (digit-- > 0 && *str != '\0')
			numf += ft_putchar(*str++);
	return (numf);
}

int	ft_putvoid_f(void *ptr, int flag, int digit)
{
	int					pt_digit;
	unsigned long int	pt;

	pt = (unsigned long int)ptr;
	pt_digit = ft_und(pt, 16) + 2;
	if (flag == 0 || flag == 1)
	{
		ft_putchar('0');
		ft_putchar('x');
		ft_putunb(pt, 16, 'x');
		while (pt_digit < digit)
		{
			ft_putchar(' ');
			pt_digit++;
		}
	}
	return (pt_digit);
}
