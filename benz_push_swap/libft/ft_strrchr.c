/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:16:02 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/20 21:45:22 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	s += i;
	while (*s != (char)c && i > 0)
	{
		s--;
		i--;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (0);
}
