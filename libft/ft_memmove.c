/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:44:22 by ptippaya          #+#    #+#             */
/*   Updated: 2022/03/25 23:51:18 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	i = 0;
	d = dest;
	s = (char *)src;
	if (d < s)
		while (++i <= n)
			d[i - 1] = s[i - 1];
	else
		while (n-- > 0)
			d[n] = s[n];
	return (d);
}
