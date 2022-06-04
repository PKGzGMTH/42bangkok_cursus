/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:16:39 by ptippaya          #+#    #+#             */
/*   Updated: 2022/06/04 22:29:03 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	print(char *s)
{
	static size_t	line = 0;

	line++;
	if (s && ft_strchr(s, '\n') == '\n')
		printf("%ld:\t%s", line, s);
	else
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
	i = 0;
	while(i < 60)
	{
		s = get_next_line(fd);
		print(s);
		//if (s)
		//	free(s);
		i++;
	}
	close(fd);
}
