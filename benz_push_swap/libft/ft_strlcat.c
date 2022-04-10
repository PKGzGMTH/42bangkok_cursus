/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:46:30 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/19 18:33:25 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;

	i = ft_strlen(dst);
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (dstsize == 0 || len_d > dstsize)
		return (dstsize + len_s);
	while (*src != '\0' && i < dstsize - 1)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (len_d + len_s);
}
