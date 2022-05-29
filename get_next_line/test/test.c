/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:38:09 by ptippaya          #+#    #+#             */
/*   Updated: 2022/05/27 21:53:17 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>

size_t	ft_strchr(char *s, char c)
{
	size_t	size;

	size = 0;
	if (!s)
		return (0);
	while (s[size] && s[size] != c)
		size++;
	if (s[size] == c)
		return (size);
	return (0);
}

char	*get_next_dest(char *rest)
{
	char	*dest;
	ssize_t	i;

	i = 0;
	dest = NULL;
	if (rest && rest[ft_strchr(rest, '\n')] == '\n')
	{
		i = (ssize_t)ft_strchr(rest, '\n');
		dest = (char *) malloc (sizeof(char) * (i + 2));
		if (!dest)
			return (NULL);
		dest[i++ + 1] = '\0';
		while (--i >= 0)
			dest[i] = rest[i];
		return (dest);
	}
	else
		return (rest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	dest = NULL;
	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (dest);
	dest = (char *) malloc (sizeof(char) * \
	(ft_strchr(s1, 0) + ft_strchr(s2, 0) + 1));
	if (!dest)
		return (0);
	while (s1 && s1[i++])
		dest[i - 1] = s1[i - 1];
	while (s2 && s2[j++])
		dest[i + j - 2] = s2[j - 1];
	dest[i + j - 2] = '\0';
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	s1 = NULL;
	s2 = NULL;
	return (dest);
}


int	main(void)
{
	puts(ft_strjoin("hello", "aaa\0"));
	return (0);
}
