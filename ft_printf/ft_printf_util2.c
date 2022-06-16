/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:57:03 by ptippaya          #+#    #+#             */
/*   Updated: 2022/06/16 19:59:49 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(size_t n)
{
	int	count;

	if (!n)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	ft_putubase(n, "0123456789abcdef", &count);
	return (count);
}

int	ft_putdec(int n)
{
	int	count;

	count = 0;
	ft_putbase(n, "0123456789", &count);
	return (count);
}

int	ft_putudec(unsigned int n)
{
	int	count;

	count = 0;
	ft_putubase(n, "0123456789", &count);
	return (count);
}

int	ft_puthexl(size_t n)
{
	int	count;

	count = 0;
	ft_putbase(n, "0123456789abcdef", &count);
	return (count);
}

int	ft_puthexu(size_t n)
{
	int	count;

	count = 0;
	ft_putbase(n, "0123456789ABCDEF", &count);
	return (count);
}
