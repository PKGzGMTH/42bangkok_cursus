/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:38:40 by ptippaya          #+#    #+#             */
/*   Updated: 2022/04/08 17:31:05 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	countstr(const char *s, char c)
{
	int		state;
	size_t	count;

	state = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && state == 0)
		{
			state = 1;
			count++;
		}
		else if (*s == c)
			state = 0;
		s++;
	}
	return (count);
}

size_t	nextstr(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (ft_strlen(s));
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	i;
	size_t	size;
	size_t	count;

	i = 0;
	size = 0;
	if (!s)
		return (0);
	count = countstr(s, c);
	dest = (char **) ft_calloc(sizeof(char *), count + 1);
	if (!dest)
		return (0);
	while (i < count)
	{
		while (*s == c)
			s++;
		size = nextstr(s, c);
		dest[i] = ft_substr(s, 0, size);
		if (!dest[i])
			return (0);
		s += size + 1;
		i++;
	}
	return (dest);
}
