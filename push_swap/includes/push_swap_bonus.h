/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:31:11 by  ptippaya         #+#    #+#             */
/*   Updated: 2022/12/02 11:39:18 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

size_t	sa(t_stack **a, t_stack **b);
size_t	sb(t_stack **a, t_stack **b);
size_t	ss(t_stack **a, t_stack **b);
size_t	pa(t_stack **a, t_stack **b);
size_t	pb(t_stack **a, t_stack **b);
size_t	ra(t_stack **a, t_stack **b);
size_t	rb(t_stack **a, t_stack **b);
size_t	rr(t_stack **a, t_stack **b);
size_t	rra(t_stack **a, t_stack **b);
size_t	rrb(t_stack **a, t_stack **b);
size_t	rrr(t_stack **a, t_stack **b);

int		checker(t_stack **a, t_stack **b);
bool	issorted(t_stack *stack);
bool	push(t_stack **stack, int num);
bool	init_stack(t_stack **stack, int argc, char **argv);
void	freestack(t_stack **stack);

#endif
