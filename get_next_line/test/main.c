/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:16:39 by ptippaya          #+#    #+#             */
/*   Updated: 2022/06/06 21:51:18 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	print(char *s)
{
	static size_t	line = 0;

	line++;
	printf("%ld:\t%s", line, s);
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
	fd = open("main.c", O_RDONLY);
	// fd = open("41_no_nl", O_RDONLY);
	i = 0;
	while(i < 60)
	{
		s = get_next_line(fd);
		print(s);
		// if (s)
			// free(s);
		i++;
	}
	close(fd);
}
