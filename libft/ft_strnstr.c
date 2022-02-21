/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:18:16 by ptippaya          #+#    #+#             */
/*   Updated: 2022/02/21 16:18:16 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_size;

	needle_size = ft_strlen(needle);
	if (!*needle || haystack == needle)
		return ((char *)haystack);
	while (*haystack && needle_size <= len)
	{
		if (!ft_strncmp(haystack, needle, needle_size))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
