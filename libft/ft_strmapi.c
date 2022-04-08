/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:06:27 by ptippaya          #+#    #+#             */
/*   Updated: 2022/04/08 13:33:15 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = 0;
	if (s && f)
	{
		dest = (char *) ft_calloc(ft_strlen(s) + 1, sizeof(char));
		if (!dest)
			return (0);
		while (s[i])
		{
			dest[i] = f(i, s[i]);
			i++;
		}
	}
	return (dest);
}
