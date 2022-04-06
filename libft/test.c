/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:18:54 by ptippaya          #+#    #+#             */
/*   Updated: 2022/04/06 17:21:13 by ptippaya         ###   ########.fr       */
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
	/* code */
	void	*ptr;
	char * s = ft_strdup((char*)"coucou");
	free(s);
	s = ft_strdup((char*)"");
	ptr = calloc (10, sizeof(int));
	free(s);
	free(ptr);
	printf("Total pass: %d\n", passcount);
	return (0);
}
