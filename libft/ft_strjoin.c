/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:16:13 by ptippaya          #+#    #+#             */
/*   Updated: 2022/04/08 13:23:48 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	if (!s1 || !s2)
		return (0);
	dest = (char *) ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (0);
	ft_bzero(dest, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strlcat(dest, s1, ft_strlen(s1) + 1);
	ft_strlcat(dest, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (dest);
}
