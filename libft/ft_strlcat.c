/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:31:24 by ptippaya          #+#    #+#             */
/*   Updated: 2022/03/29 14:04:34 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = ft_strlen(dst);
	if (n == 0)
		return (ft_strlen(src));
	else if (n <= i)
		return (ft_strlen(src) + n);
	else
	{
		while (*src && i < n - 1)
			dst[i++] = *src++;
		return (ft_strlen(dst) + ft_strlen(src));
	}
}
