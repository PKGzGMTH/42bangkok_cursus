/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:18:54 by ptippaya          #+#    #+#             */
/*   Updated: 2022/02/21 16:39:24 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] == s2[i] && s1 && s2 && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_size;

	needle_size = ft_strlen(needle);
	if (!*needle || haystack == needle)
		return ((char *)haystack);
	while (*haystack && needle_size <= len--)
	{
		if (!ft_strncmp(haystack, needle, needle_size))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}


char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *) s);
	else
		return (0);
}

int main() {
	const char a[] = "yoloooz";
	const char b[] = "lo";
	puts(ft_strnstr(a, b, 3));
	return 0;
}
