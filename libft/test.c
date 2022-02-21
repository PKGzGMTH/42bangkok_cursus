/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:18:54 by ptippaya          #+#    #+#             */
/*   Updated: 2022/02/19 15:47:58 by peakungg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<stdio.h>
#include	<ctype.h>
#include	<string.h>
#include	"libft.h"

int	main(void)
{
	char	s[10];
	strcpy(s, "yolooo");
	printf("%s$\n", (char *)memmove(s, s+2, 4));

	for (int i = 0; i < 10; i++)
		putchar(s[i]);
	putchar('\n');

	strcpy(s, "yolooo");
	printf("%s$\n", (char *)ft_memmove(s, s+2, 4));

	for (int i = 0; i < 10; i++)
		putchar(s[i]);
	putchar('\n');
	return (0);
}
