/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:22:51 by ptippaya          #+#    #+#             */
/*   Updated: 2022/09/03 17:23:55 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(arg, size_t)));
	else if (c == 'd' || c == 'i')
		return (ft_putdec(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_putudec(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (ft_puthexl(va_arg(arg, unsigned int)));
	else if (c == 'X')
		return (ft_puthexu(va_arg(arg, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		size;
	size_t	i;
	va_list	arg;

	i = 0;
	size = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
			size += ft_printf_format(format[++i], arg);
		else
			size += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (size);
}
