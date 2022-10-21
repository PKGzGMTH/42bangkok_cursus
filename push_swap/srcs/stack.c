/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:42:41 by ptippaya          #+#    #+#             */
/*   Updated: 2022/10/21 15:09:55 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

/*
 * Function:	isdup
 * -----------------
 *	Check the integer is duplicate in stack
 *
 *	returns:	1 (Integer is duplicate)
 *				0 (Integer is not duplicate)
 */

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

/*
 * Function:	push
 * -----------------
 *	Create new node with int data (num)
 *	it will push new node in back of last node.
 *	if stack empty it will create new node as head of stack.
 *
 *	returns:	1 (Successful)
 *				0 (Memory allocation Error or integer are duplicate)
 */

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

/*
 * Function:	freestack
 * ----------------------
 *	Free all node node in stack
 */

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

/*
 * Function:	init_index
 * -----------------------
 *	initial index of each node in stack
 */

void	init_index(t_stack *stack)
{
	t_stack			*cur;
	t_stack			*head;

	cur = stack;
	while (cur)
	{
		cur->index = 0;
		head = stack;
		while (head)
		{
			if (head->data < cur->data)
				cur->index += 1;
			head = head->next;
		}
		cur = cur->next;
	}
}
