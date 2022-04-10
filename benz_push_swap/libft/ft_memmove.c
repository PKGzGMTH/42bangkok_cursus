/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:36:51 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/21 20:42:49 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	char			*s_dst;
	const char		*s_src;

	s_dst = dst;
	s_src = src;
	if (s_src < s_dst)
	{
		i = len;
		while (i-- > 0)
			s_dst[i] = s_src[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			s_dst[i] = s_src[i];
			i++;
		}
	}
	return (dst);
}
