/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:10:08 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/17 20:11:06 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_element(char const *s, char c)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			e++;
		i++;
	}
	return (e);
}

static void	ft_esplit(char **split, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] == c)
			j++;
		else
		{
			k = 0;
			while (s[j + k] != c && s[j + k] != '\0')
				k++;
			split[i] = malloc(sizeof(**split) * (k + 1));
			k = 0;
			while (s[j] != c && s[j] != '\0')
				split[i][k++] = s[j++];
			split[i++][k] = '\0';
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		e;

	e = ft_element(s, c);
	split = malloc(sizeof(*split) * (e + 1));
	if (split == NULL)
		return (0);
	split[e] = 0;
	ft_esplit(split, s, c);
	return (split);
}
