/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:42:41 by ptippaya          #+#    #+#             */
/*   Updated: 2022/12/01 00:34:20 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

static bool	isdup(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->data == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

bool	push(t_stack **stack, int num)
{
	t_stack	*cur;

	if (isdup(*stack, num))
		return (0);
	if (!*stack)
	{
		*stack = (t_stack *) malloc(sizeof(t_stack));
		if (!*stack)
			return (0);
		(*stack)->data = num;
		(*stack)->next = NULL;
	}
	else
	{
		cur = *stack;
		while (cur->next)
			cur = cur->next;
		cur->next = (t_stack *) malloc(sizeof(t_stack));
		if (!cur->next)
			return (0);
		cur->next->data = num;
		cur->next->next = NULL;
	}
	return (1);
}

void	freestack(t_stack **stack)
{
	t_stack	*del;

	while (*stack)
	{
		del = *stack;
		*stack = (*stack)->next;
		free(del);
	}
	*stack = NULL;
}

size_t	length(t_stack *stack)
{
	size_t	length;

	length = 0;
	while (stack)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

bool	issorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->next && stack->next->data < stack->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	print_stack(t_stack *a, t_stack *b, char *s)
{
	printf("====== %s ====== \n", s);
	printf("------------------------------------\n");
	while (a)
	{
		printf("%d -> ", a->data);
		a = a->next;
	}
	printf ("NULL\n");
	while (b)
	{
		printf("%d -> ", b->data);
		b = b->next;
	}
	printf ("NULL\n");
	printf("------------------------------------\n");
	fflush(stdout);
}
