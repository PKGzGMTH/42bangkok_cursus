/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:01:51 by ptippaya          #+#    #+#             */
/*   Updated: 2022/02/17 22:01:51 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str_src;
	char	*str_dest;
	size_t	i;

	i = 0;
	str_dest = dest;
	str_src = (char *)src;
	while (str_src[i] && i < n)
	{
		str_dest[i] = str_src[i];
		i++;
	}
	return (dest);
}
