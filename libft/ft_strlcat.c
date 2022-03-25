/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:31:24 by ptippaya          #+#    #+#             */
/*   Updated: 2022/03/25 23:51:39 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (ft_strlen(dst) < n)
		return (ft_strlen(dst) + ft_strlen(src));
	else
	{
		while (*src && i < n - 1)
			dst[i++] = *src++;
		dst[i] = 0;
		return (ft_strlen(dst) + n);
	}
}
