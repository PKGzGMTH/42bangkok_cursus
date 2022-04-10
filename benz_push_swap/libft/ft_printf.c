/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:06:16 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/25 00:14:40 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checktype(int c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if (c == 'p')
		return (3);
	else if (c == 'd' || c == 'i')
		return (4);
	else if (c == 'u')
		return (5);
	else if (c == 'x')
		return (6);
	else if (c == 'X')
		return (7);
	else if (c == '%')
		return (8);
	return (0);
}

static int	ft_checkflag(int c)
{
	if (c == '-')
		return (1);
	else if (c == '0')
		return (2);
	else if (c == '.')
		return (3);
	else if (c == '#')
		return (4);
	else if (c == ' ')
		return (5);
	else if (c == '+')
		return (6);
	else if (c > '0' && c <= '9')
		return (7);
	return (0);
}

static int	ft_putft(va_list var, int flag, int type, int digit)
{
	int	numf;

	numf = 0;
	if (type == 1)
		numf = ft_putchar_f(va_arg(var, int), flag, digit);
	else if (type == 2)
		numf = ft_putstr_f(va_arg(var, const char *), flag, digit);
	else if (type == 3)
		numf = ft_putvoid_f(va_arg(var, void *), flag, digit);
	else if (type == 4)
		numf = ft_putnbr_f(va_arg(var, int), flag, digit);
	else if (type == 5)
		numf = ft_putunb_f(va_arg(var, unsigned int), flag, digit);
	else if (type == 6)
		numf = ft_puthex_f(va_arg(var, unsigned int), 'x', flag, digit);
	else if (type == 7)
		numf = ft_puthex_f(va_arg(var, unsigned int), 'X', flag, digit);
	return (numf);
}

static int	ft_putf(const char *format, int index, va_list var)
{
	int	f;
	int	t;
	int	digit;
	int	numf;

	numf = 0;
	if (ft_checktype(format[index]) == 8)
	{
		ft_putchar('%');
		return (1);
	}
	f = ft_checkflag(format[index]);
	if (f > 0 && f != 7)
		index++;
	digit = 0;
	if ((f >= 1 && f <= 3) || f == 7)
		while (format[index] >= '0' && format[index] <= '9')
			digit = (digit * 10) + (format[index++] - '0');
	t = ft_checktype(format[index]);
	if (t > 0 && t != 8)
		numf = ft_putft(var, f, t, digit);
	return (numf);
}

int	ft_printf(const char *format, ...)
{
	va_list	var;
	int		i;
	int		k;
	int		numf;

	va_start(var, format);
	i = 0;
	k = 0;
	numf = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && k == 0)
			k = i + 1;
		else if (k > 0 && ft_checktype(format[i]) > 0)
		{
			numf += ft_putf(format, k, var);
			k = 0;
		}
		else if (k == 0)
			numf += ft_putchar(format[i]);
		i++;
	}
	va_end(var);
	return (numf);
}
