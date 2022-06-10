/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:55:09 by ptippaya          #+#    #+#             */
/*   Updated: 2022/06/10 23:30:33 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strchr(char *s, char c)
{
	size_t	size;

	size = 0;
	if (!s)
		return (0);
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	total;
	char	*dest;

	i = 0;
	j = 0;
	dest = NULL;
	if (!s1 && !s2)
		return (dest);
	total = ft_strchr(s1, '\0') + ft_strchr(s2, '\0');
	dest = (char *) malloc (sizeof(char) * (total + 1));
	if (!dest)
		return (0);
	while (s1 && s1[j] && i < total)
		dest[i++] = s1[j++];
	while (s2 && *s2 && i < total)
		dest[i++] = *(s2++);
	dest[i] = '\0';
	if (s1)
		free(s1);
	s1 = NULL;
	return (dest);
}

t_list	*get_next_list(t_list **list, int fd)
{
	t_list	*dest;
	t_list	*buff;

	buff = *list;
	while (buff && buff->next && buff->next->fd <= fd)
		buff = buff->next;
	if (buff && buff->fd == fd)
		return (buff);
	dest = (t_list *) malloc (sizeof(t_list));
	if (!dest)
		return (NULL);
	dest->fd = fd;
	dest->rest = NULL;
	dest->next = NULL;
	if (buff && buff->next)
		dest->next = buff->next;
	if (buff)
		buff->next = dest;
	else
		*list = dest;
	return (dest);
}

void	get_next_clean(t_list **list)
{
	t_list	*curr;
	t_list	*next;

	curr = *list;
	next = NULL;
	while (curr && curr->next)
	{
		if (curr && curr->next && !curr->next->rest)
		{
			if (curr->next->next)
				next = curr->next->next;
			else
				next = NULL;
			free (curr->next);
			curr->next = next;
		}
		else if (curr->next)
			curr = curr->next;
	}
	if (*list && !(*list)->rest)
	{
		next = (*list)->next;
		free(*list);
		*list = next;
	}
}
