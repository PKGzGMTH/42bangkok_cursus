/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:43:13 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/17 13:52:01 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(*s3) * (len + 1));
	if (s3 == NULL)
		return (0);
	while (*s1 != '\0')
		*s3++ = *s1++;
	while (*s2 != '\0')
		*s3++ = *s2++;
	*s3 = '\0';
	return (s3 - len);
}
