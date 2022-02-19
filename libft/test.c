/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:18:54 by ptippaya          #+#    #+#             */
/*   Updated: 2022/02/18 17:28:15 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<stdio.h>
#include	<ctype.h>
#include	<string.h>
#include	"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);

int	main(void)
{
	char	s[10];
	strcpy(s, "yolooo");
	printf("%s$\n", (char *)memcpy(s+1, s, 4));

	for (int i = 0; i < 10; i++)
		putchar(s[i]);
	putchar('\n');

	strcpy(s, "yolooo");
	printf("%s$\n", (char *)ft_memcpy(s+1, s, 4));

	for (int i = 0; i < 10; i++)
		putchar(s[i]);
	putchar('\n');
	return (0);
}
