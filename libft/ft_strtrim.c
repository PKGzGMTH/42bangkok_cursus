/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:56:16 by ptippaya          #+#    #+#             */
/*   Updated: 2022/04/08 11:15:08 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			size = i;
		i++;
	}
	dest = ft_substr(s1, 0, size + 1);
	return (dest);
}
