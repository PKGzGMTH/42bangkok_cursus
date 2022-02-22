/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:18:54 by ptippaya          #+#    #+#             */
/*   Updated: 2022/02/22 23:04:59 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

void	check(int i)
{
	if (i)
		printf("\x1b[38;5;43mpass\e[0m\n");
	else
		printf("\x1b[38;5;198merr\e[0m\n");
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (ft_strlen(src) < n || n <= 0)
		return (ft_strlen(dst) + ft_strlen(src));
	else
	{
		while (*src && i < n - 1)
			dst[i++] = *src++;
		dst[i] = 0;
		return (ft_strlen(dst) + n);
	}
}

int	main(void)
{
	char dest[30]; memset(dest, 0, 30);
	char * src = (char *)"AAAAAAAAA";
	dest[0] = 'B';
	/* 1 */ check(ft_strlcat(dest, src, 0) == strlen(src) && !strcmp(dest, "B"));
	dest[0] = 'B';
	/* 2 */ check(ft_strlcat(dest, src, 1) == 10 && !strcmp(dest, "B"));
	memset(dest, 'B', 4);
	/* 3 */ check(ft_strlcat(dest, src, 3) == 3 + strlen(src) && !strcmp(dest, "BBBB"));
	/* 4 */ check(ft_strlcat(dest, src, 6) == 13 && !strcmp(dest, "BBBBA"));
	memset(dest, 'C', 5);
	/* 5 */ check(ft_strlcat(dest, src, -1) == 14 && !strcmp(dest, "CCCCCAAAAAAAAA"));
	/* 6 */ check(ft_strlcat(dest, src, 17) == 24 && !strcmp(dest, "CCCCCCCCCCCCCCCA"));
	memset(dest, 0, 30);
	/* 7 */ check(ft_strlcat(dest, src, 1) == strlen(src) && !strcmp(dest, ""));
	memset(dest, 0, 30); memset(dest, '1', 10);
	/* 8 */ check(ft_strlcat(dest, src, 5) == strlen(src) + 5 && !strcmp(dest, "1111111111"));
	memset(dest, 0, 30); memset(dest, '1', 10);
	/* 9 */ check(ft_strlcat(dest, src, 5) == strlen(src) + 5 && !strcmp(dest, "1111111111"));
	memset(dest, 0, 30); memset(dest, '1', 10);
	/* 10 */ check(ft_strlcat(dest, "", 15) == 10 && !strcmp(dest, "1111111111"));
	memset(dest, 0, 30);
	/* 11 */ check(ft_strlcat(dest, "", 42) == 0 && !strcmp(dest, ""));
	memset(dest, 0, 30);
	/* 12 */ check(ft_strlcat(dest, "", 0) == 0 && !strcmp(dest, ""));
	memset(dest, 0, 30);
	/* 13 */ check(ft_strlcat(dest, "123", 1) == 3 && !strcmp(dest, ""));
	memset(dest, 0, 30);
	/* 14 */ check(ft_strlcat(dest, "123", 2) == 3 && !strcmp(dest, "1"));
	memset(dest, 0, 30);
	/* 15 */ check(ft_strlcat(dest, "123", 3) == 3 && !strcmp(dest, "12"));
	memset(dest, 0, 30);
	/* 16 */ check(ft_strlcat(dest, "123", 4) == 3 && !strcmp(dest, "123"));
	memset(dest, 0, 30);
	/* 17 */ check(ft_strlcat(dest, "123", 0) == 3 && !strcmp(dest, ""));
	write(1, "\n", 1);
	return (0);
}

