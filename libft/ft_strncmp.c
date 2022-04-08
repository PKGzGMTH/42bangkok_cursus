/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:37:22 by ptippaya          #+#    #+#             */
/*   Updated: 2022/04/08 12:49:39 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (*((unsigned char *)s1 + i) == *((unsigned char *)s2 + i) \
						&& *((unsigned char *)s1 + i) && i < n - 1)
		i++;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
