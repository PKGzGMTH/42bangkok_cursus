/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:57:03 by ptippaya          #+#    #+#             */
/*   Updated: 2022/06/16 19:59:22 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putbase(ssize_t n, char *s, int *count)
{
	ssize_t	base;

	base = ft_strlen(s);
	if (n < 0)
	{
		*count += ft_putchar('-');
		n = -n;
	}
	if (n >= base)
	{
		ft_putbase(n / base, s, count);
		ft_putbase(n % base, s, count);
	}
	else
		*count += ft_putchar(s[n]);
	return (0);
}

int	ft_putubase(size_t n, char *s, int *count)
{
	size_t	base;

	base = ft_strlen(s);
	if (n >= base)
	{
		ft_putbase(n / base, s, count);
		ft_putbase(n % base, s, count);
	}
	else
		*count += ft_putchar(s[n]);
	return (0);
}
