/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:56:52 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/21 00:11:15 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				break ;
			else if (s1[i] != set[j] && set[j + 1] == '\0')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

static int	ft_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	i -= 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				break ;
			else if (s1[i] != set[j] && set[j + 1] == '\0')
				return (i);
			j++;
		}
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		len;
	int		start;
	int		end;

	if (*set == '\0')
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start <= end && *s1 != '\0')
		len = end - start + 1;
	else
		len = 0;
	s2 = malloc(sizeof(*s2) * (len + 1));
	if (s2 == NULL)
		return (0);
	i = 0;
	while (start <= end && len > 0)
		s2[i++] = s1[start++];
	s2[i] = '\0';
	return (s2);
}
