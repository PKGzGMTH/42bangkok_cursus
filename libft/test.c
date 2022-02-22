/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:18:54 by ptippaya          #+#    #+#             */
/*   Updated: 2022/02/22 13:56:59 by ptippaya         ###   ########.fr       */
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
		printf("pass\n");
	else
		printf("err\n");
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
	{
		while (src[i++])
			;
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

int	main(void)
{
	char src[] = "coucou";
	char dest[10]; memset(dest, 'A', 10);
	/* 1 */ check(ft_strlcpy(dest, src, 0) == strlen(src) && dest[0] == 'A');
	/* 2 */ check(ft_strlcpy(dest, src, 1) == strlen(src) && dest[0] == 0 && dest[1] == 'A');
	/* 3 */ check(ft_strlcpy(dest, src, 2) == strlen(src) && dest[0] == 'c' && dest[1] == 0  && dest[2] == 'A');
	/* 4 */ check(ft_strlcpy(dest, src, -1) == strlen(src) && !strcmp(src, dest) && dest[strlen(src) + 1] == 'A');
	/* 5 */ check(ft_strlcpy(dest, src, 6) == strlen(src) && !memcmp(src, dest, 5) && dest[5] == 0);
	/* 6 */ check(ft_strlcpy(dest, src, 7) == strlen(src) && !memcmp(src, dest, 7));
	/* 7 */ check(ft_strlcpy(dest, src, 8) == strlen(src) && !memcmp(src, dest, 7));
	/* 8 */ check(ft_strlcpy(dest, "", 42) == 0 && !memcmp("", dest, 1));
	/* 9 */ check(ft_strlcpy(dest, "1", 0) == 1 && dest[0] == 0);
	write(1, "\n", 1);
	return (0);
}
