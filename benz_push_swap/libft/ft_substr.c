/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:35:56 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/20 21:34:58 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (i <= start)
		len = 0;
	else if (i > start && i < start + len)
		len = i - start;
	sub = malloc(sizeof(*sub) * (len + 1));
	if (sub == NULL)
		return (0);
	i = 0;
	while (len--)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
