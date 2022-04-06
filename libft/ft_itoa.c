/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:04:22 by ptippaya          #+#    #+#             */
/*   Updated: 2022/04/07 00:18:38 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	tostrsize(int n,int *multiple)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		*multiple = -1;
		n *= -1;
		size++;
	}
	else
		*multiple = 1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		multiple;
	size_t	size;

	if (n == 0)
		dest = ft_strdup("0");
	else if (n == -2147483648)
		dest = ft_strdup("-2147483648");
	else
	{
		size = tostrsize(n, &multiple);
		dest = (char *) ft_calloc(size + 1, sizeof(char));
		if (multiple == -1)
			dest[0] = '-';
		while (size > 0 && dest[size - 1] != '-')
		{
			dest[size - 1] = (char) (n % 10) + '0';
			n /= 10;
			size--;
		}
	}
	return (dest);
}
