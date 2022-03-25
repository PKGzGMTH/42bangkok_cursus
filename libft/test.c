/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:18:54 by ptippaya          #+#    #+#             */
/*   Updated: 2022/03/25 23:56:05 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

void check(int value)
{
	static int count = 0;

	count++;
	if (value)
		printf("[%d] \e[38;5;49mPass\e[0;m\n", count);
	else
		printf("[%d] \e[38;5;197mError\e[0;m\n", count);
}

int	main(void)
{
	/* test code */
}

