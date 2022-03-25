/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:53:00 by ptippaya          #+#    #+#             */
/*   Updated: 2022/03/25 23:50:43 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	i = 0;
	chr = c;
	str = (unsigned char *) s;
	if (n == 0)
		return (0);
	while (str[i] != chr && i < n)
		i++;
	if (str[i] == chr)
		return (str + i);
	else
		return (0);
}
