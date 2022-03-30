/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:00:54 by ptippaya          #+#    #+#             */
/*   Updated: 2022/03/30 19:27:58 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;

	if (nmemb <= 0 || size <= 0)
		return (0);
	dst = malloc (nmemb * size);
	if (!dst)
		return (0);
	ft_bzero(dst, nmemb * size);
	return (dst);
}
