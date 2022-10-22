/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:31:11 by  ptippaya         #+#    #+#             */
/*   Updated: 2022/10/22 12:13:10 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	unsigned int	index;
	struct s_stack	*next;
}	t_stack;

void	sa(t_stack **a, t_stack **b);
void	sb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, t_stack **b);
void	rb(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, t_stack **b);
void	rrb(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

bool	init_stack(t_stack **stack, int argc, char **argv);
bool	push(t_stack **stack, int num);
void	freestack(t_stack **stack);
void	init_index(t_stack *stack);
void	push_swap3(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b);

void	print_stack(t_stack *a, t_stack *b);

#endif
