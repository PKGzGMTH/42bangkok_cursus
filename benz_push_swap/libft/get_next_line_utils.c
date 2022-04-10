/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:25:57 by brangrae          #+#    #+#             */
/*   Updated: 2022/02/22 22:50:50 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_linedup(char *line, int len)
{
	char	*new;
	int		i;

	new = malloc(sizeof(*new) + (len + 2));
	if (new == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\n';
	new[i + 1] = '\0';
	if (len > 0)
		free(line);
	return (new);
}
