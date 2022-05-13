/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:55:09 by ptippaya          #+#    #+#             */
/*   Updated: 2022/05/13 00:01:36 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = nextchr(dst, 0);
	if (dstsize <= len)
		return (nextchr((char *)src, 0) + dstsize);
	while (len < dstsize - 1 && *src)
		dst[len++] = *src++;
	dst[len] = 0;
	return (len + nextchr((char *)src, 0));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;
	size_t	i;

	i = 0;
	if (nmemb * size < nmemb && nmemb * size < size)
		return (0);
	else if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	dst = malloc (nmemb * size);
	if (!dst)
		return (0);
	while (i < nmemb * size)
		((char *)(dst + i++))[0] = 0;
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	else
	{
		while (i < n - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
		while (src[i])
			i++;
		return (i);
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	char	*temp;

	if (!s)
		return (0);
	if (nextchr((char *)s, 0) <= start || !s)
		return (ft_calloc(sizeof(char), 1));
	temp = (char *) s + start;
	if (nextchr(temp, 0) < len)
		len = nextchr(temp, 0);
	dest = (char *) ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s + start, len + 1);
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (s2);
	else if (!s2)
		return (s1);
	dest = (char *) ft_calloc(sizeof(char), \
	nextchr(s1, 0) + nextchr(s2, 0) + 1);
	if (!dest)
		return (0);
	ft_strlcat(dest, s1, nextchr(s1, 0) + 1);
	ft_strlcat(dest, s2, nextchr(s1, 0) + nextchr(s2, 0) + 1);
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
	return (dest);
}
