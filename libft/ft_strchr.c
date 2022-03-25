/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:19:36 by ptippaya          #+#    #+#             */
/*   Updated: 2022/03/25 23:51:33 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char) c;
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *) s);
	else
		return (0);
}
