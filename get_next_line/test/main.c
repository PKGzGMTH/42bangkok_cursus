/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:16:39 by ptippaya          #+#    #+#             */
/*   Updated: 2022/05/24 14:20:07 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>

void	print(char *s)
{
	static size_t	line = 0;

	line++;
	printf("%ld:%s", line, s);
}

void	check(int i)
{
	if (i)
		printf("TRUE\n");
	else
		printf("FALSE\n");
}

int	main(void)
{
	char	*s;
	size_t	i;

	i = 0;
	while(i < 6)
	{
		s = get_next_line(0);
		print(s);
		if (s)
			free(s);
		i++;
	}
}
