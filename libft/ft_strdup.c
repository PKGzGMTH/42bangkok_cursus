/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:45:57 by ptippaya          #+#    #+#             */
/*   Updated: 2022/03/30 19:50:56 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	size;

	size = ft_strlen(s);
	dst = (char *) malloc (sizeof(char) * (size + 1));
	if (!dst)
		return (0);
	ft_memcpy(dst, s, size);
	return (dst);
}
