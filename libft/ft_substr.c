/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:21:28 by ptippaya          #+#    #+#             */
/*   Updated: 2022/04/06 17:31:52 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	char	*temp;

	dest = ft_calloc(sizeof(char), 1);
	dest[0] = 0;
	if (ft_strlen(s) <= start)
		return (dest);
	temp = (char *) s + start;
	if (ft_strlen(temp) < len)
		len = ft_strlen(temp);
	dest = (char *) ft_calloc(sizeof(char), len + 1);
	if (!dest)
		return (0);
	ft_strlcpy(dest, s + start, len + 1);
	return (dest);
}
