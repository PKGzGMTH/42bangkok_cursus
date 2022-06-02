/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:16:39 by ptippaya          #+#    #+#             */
/*   Updated: 2022/06/02 21:27:17 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	print(char *s)
{
	static size_t	line = 0;

	line++;
	if (s)
		printf("%ld:%s", line, s);
	else
		printf("%ld:%s\n", line, s);
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
	int		fd;
	char	*s;
	size_t	i;

	// fd = open("test.txt", O_RDONLY);
	fd = open("test_nonl.txt", O_RDONLY);
	i = 0;
	while(i < 10)
	{
		s = get_next_line(fd);
		print(s);
		if (s)
			free(s);
		i++;
	}
	close(fd);
}
