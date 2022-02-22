/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:29:54 by ptippaya          #+#    #+#             */
/*   Updated: 2022/02/20 22:29:54 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	last;
	size_t	len;

	i = 0;
	last = 0;
	len = ft_strlen(s);
	c = (unsigned char) c;
	while (i <= len)
	{
		if (s[i] == c)
			last = i;
		i++;
	}
	if (s[last] == c)
		return ((char *) s + last);
	else
		return (0);
}
