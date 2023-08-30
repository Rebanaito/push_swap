/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 02:42:56 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/22 10:22:21 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_op
{
	char		*str;
	struct s_op	*next;
}	t_op;

int		input(int argc, char **argv, t_stack **a);
void	clear_stack(t_stack **a);
int		push(t_stack **a, int value);
t_stack	*pop(t_stack **a);
int		stack_size(t_stack *a);
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);
int		a_sorted(t_stack *a);
int		b_sorted(t_stack *b);
int		bottom(t_stack *a);
int		stack_len(t_stack *a);
void	short_sort(t_stack **a);
void	long_sort(t_stack **a);
void	print_stack(t_stack *a);
int		finish_up(t_stack *a);
int		finish_up_b(t_stack *b);
int		a_closest(int b, t_stack *a);
int		b_closest(int a, t_stack *b);
int		top_to_closest(int closest, t_stack *b);
void	push_to_b(t_stack **a, t_stack **b);
void	push_to_a(t_stack **a, t_stack **b);
void	move_stacks(t_stack **a, t_stack **b, int a_best, int b_best);
void	best_route(t_stack *a, t_stack *b, int *a_best, int *b_best);
void	last_chunk(t_stack **a, t_stack **b, int size);
int		a_closest_chunk(int b, t_stack *a, int nums[], int size);
int		b_closest_chunk(int a, t_stack *b, int nums[]);
int		is_nums(int num, int nums[], int size);
void	comparison(int *a_best, int *b_best, int i, int j);
void	best_route_chunk(t_stack **a, t_stack **b, int nums[]);
int		where_a(t_stack *a, t_stack *p, int i, int j);
int		where_b(t_stack *a, t_stack *p, int i, int j);
void	print_ops(t_op *op);
int		push_op(t_op **op, char *str);

#endif	//	PUSH_SWAP_H