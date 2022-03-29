/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:18:54 by ptippaya          #+#    #+#             */
/*   Updated: 2022/03/29 14:06:37 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

unsigned int passcount = 0;

void check(int value)
{
	static int count = 0;

	count++;
	if (value)
	{
		printf("[%d] \e[38;5;49mPass\e[0;m\n", count);
		passcount++;
	}
	else
		printf("[%d] \e[38;5;197mError\e[0;m\n", count);
}

void showLeaks()
{
	;
}

int	main(void)
{
	printf("Total pass: %d\n", passcount);
}
