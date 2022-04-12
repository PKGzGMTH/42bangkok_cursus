/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:16:39 by ptippaya          #+#    #+#             */
/*   Updated: 2022/04/12 19:30:15 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>

void	print(char *s)
{
	static size_t	line;

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

	s = get_next_line(0);
	print(s);
	free(s);
	s = get_next_line(0);
	print(s);
	free(s);
	s = get_next_line(0);
	print(s);
	free(s);
	s = get_next_line(0);
	print(s);
	free(s);
	s = get_next_line(0);
	print(s);
	free(s);
}
