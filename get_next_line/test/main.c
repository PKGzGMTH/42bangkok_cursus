/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:16:39 by ptippaya          #+#    #+#             */
/*   Updated: 2022/06/11 20:51:21 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>

void	print(char *s)
{
	static size_t	line = 0;

	line++;
	if (s && s[ft_strchr(s, '\n')] == '\n')
		printf("%ld:\t%s", line, s);
	else
		printf("%ld:\t%s\n", line, s);
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
	int		fd[3];
	char	*s;
	size_t	i;

	fd[0] = open("41_with_nl", O_RDONLY);
	fd[1] = open("42_with_nl", O_RDONLY);
	fd[2] = open("43_with_nl", O_RDONLY);
	// fd = open("41_no_nl", O_RDONLY);
	i = 0;
	while (i < 3)
	{
		s = get_next_line(fd[0]);
		print(s);
		if (s)
			free(s);
		s = get_next_line(fd[1]);
		print(s);
		if (s)
			free(s);
		s = get_next_line(fd[2]);
		print(s);
		if (s)
			free(s);
		i++;
	}
	// i = 0;
	// while (i < 3)
	// {
	// 	s = get_next_line(fd[1]);
	// 	print(s);
	// 	i++;
	// }
	// i = 0;
	// while (i < 3)
	// {
	// 	s = get_next_line(fd[2]);
	// 	print(s);
	// 	i++;
	// }
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
}
