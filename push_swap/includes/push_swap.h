/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptippaya <ptippaya@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:31:11 by  ptippaya         #+#    #+#             */
/*   Updated: 2022/12/01 20:39:23 by ptippaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_count
{
	unsigned int	up;
	unsigned int	down;
}	t_count;

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

int		*sorted_array(t_stack *stack);
int		get_med(t_stack *stack, size_t n);
bool	issorted(t_stack *stack);
bool	push(t_stack **stack, int num);
bool	init_stack(t_stack **stack, int argc, char **argv);
void	freestack(t_stack **stack);
void	sort_a(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b);
void	dual_swap(t_stack **a, t_stack **b);
void	push_back_range(t_stack **a, t_stack **b, size_t n);
size_t	length(t_stack *stack);
size_t	push_med_2b(t_stack **a, t_stack **b);
size_t	push_back(t_stack **a, t_stack **b, size_t n);
size_t	psloop(t_stack **a, t_stack **b, \
		size_t (*function)(t_stack **, t_stack **), int count);

#endif
