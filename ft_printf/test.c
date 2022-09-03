/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:52:34 by ptippaya          #+#    #+#             */
/*   Updated: 2022/07/10 09:54:14 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	*s;
	int		count1;
	int		count2;

	s = NULL;
	count1 = ft_printf("%s\n", s);
	count2 = printf("%s\n", s);
	printf("%d %d\n", count1, count2);
	ft_printf("This %p is even stranger\n", (void *)-1);
	printf("This %p is even stranger\n", (void *)-1);
	printf("%lu\n", (size_t) -1);
	ft_printf("hello world %s.\n", "PPAP");
	printf("%lu %lu %lu\n", sizeof(char), sizeof(short), sizeof(int));
	// printf("%d\n", printf("aaa\n"));
	// printf("|%d|\n|%-1.2d|\n", 255, 123);
	// printf("%ln\n", &ptr);
	// printf("%%'\\\n");
	// printf("%d\n", printf("%d\n", 1234));
	return (0);
}
