/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brangrae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:17:29 by brangrae          #+#    #+#             */
/*   Updated: 2022/04/10 19:02:04 by brangrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int	max;
	int	top;
	int	*arr;
}	t_stack;

void	ft_error(char *str);
void	ft_swap(int *a, int *b);
void	swap_a(t_stack *stack_a, int flag);
void	swap_b(t_stack *stack_b, int flag);
void	swap_ab(t_stack *stack_a, t_stack *stack_b, int flag);
int		fl(t_stack *stack, int m, int range);
int		isfull(t_stack *stack);
int		isempty(t_stack *stack);
void	push_a(t_stack *stack_a, t_stack *stack_b, int flag);
void	push_b(t_stack *stack_a, t_stack *stack_b, int flag);
t_stack	*ft_stack(int size);
void	rotate_a(t_stack *stack_a, int flag);
void	rotate_b(t_stack *stack_b, int flag);
void	rotate_ab(t_stack *stack_a, t_stack *stack_b, int flag);
int		*copyint(t_stack *stack);
void	rrotate_a(t_stack *stack_a, int flag);
void	rrotate_b(t_stack *stack_b, int flag);
void	rrotate_ab(t_stack *stack_a, t_stack *stack_b, int flag);
int		issort(t_stack *stack, int type);
int		ps_solve(t_stack *stack_a, t_stack *stack_b);
int		ismax(t_stack *stack, int pos);
int		ismin(t_stack *stack, int pos);
int		min_neartop(t_stack *stack);
int		max_neartop(t_stack *stack);
void	ft_release(t_stack *stack);
int		intmin(t_stack *stack);
int		intmax(t_stack *stack);
int		f_neartop(t_stack *stack, int floor, int type);
t_stack	*ft_sort(t_stack *stack);
int		iscycle(t_stack *stack);
int		dot_neartop(t_stack *stack);
int		spot_neartop(t_stack *stack, int mark);
int		range(int max);
int		max_pos(t_stack *stack);
int		spot_pos(t_stack *stack, int mark);
void	ps_fillb(t_stack *stack_a, t_stack *stack_b, int floor, int med);
void	ps_filla(t_stack *stack_a, t_stack *stack_b, int floor, int med);
void	ps_cal_1_sub1(t_stack *stack_a, t_stack *stack_b);
void	ps_cal_2_sub1(t_stack *stack_a, t_stack *stack_b);
void	ps_cal_2_sub2(t_stack *stack_a, t_stack *stack_b);
void	ps_cal_2_sub3(t_stack *stack_a, t_stack *stack_b);
void	ps_cal_2_sub4(t_stack *stack_a, t_stack *stack_b);
int		ps_read(t_stack *stack_a, t_stack *stack_b);

#endif
