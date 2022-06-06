/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:55:09 by ptippaya          #+#    #+#             */
/*   Updated: 2022/06/06 20:00:43 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strchr(char *s, char c)
{
	size_t	size;

	size = 0;
	if (!s)
		return (0);
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	total;
	char	*dest;

	i = 0;
	j = 0;
	dest = NULL;
	if (!s1 && !s2)
		return (dest);
	total = ft_strchr(s1, '\0') + ft_strchr(s2, '\0');
	dest = (char *) malloc (sizeof(char) * (total + 1));
	if (!dest)
		return (0);
	while (s1 && s1[j] && i < total)
		dest[i++] = s1[j++];
	while (s2 && *s2 && i < total)
		dest[i++] = *(s2++);
	dest[i] = '\0';
	if (s1)
		free(s1);
	s1 = NULL;
	return (dest);
}
