/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 02:09:50 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/22 11:14:06 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

void	push_a(t_stack **a, t_stack **b, int size)
{
	int	a_best;
	int	b_best;

	while (stack_len(*a) > size)
	{
		a_best = -2147483648;
		b_best = -2147483648;
		best_route(*a, *b, &a_best, &b_best);
		move_stacks(a, b, a_best, b_best);
		pb(a, b, 1);
	}
	last_chunk(a, b, size);
}

void	push_b(t_stack **a, t_stack **b)
{
	if (!finish_up_b(*b))
		while (!b_sorted(*b))
			rrb(b, 1);
	else
		while (!b_sorted(*b))
			rb(b, 1);
	while (*b)
	{
		if (stack_len(*a) > 1)
			while ((*a)->value != a_closest((*b)->value, *a))
				rra(a, 1);
		pa(a, b, 1);
	}
	if (!finish_up(*a))
		while (!a_sorted(*a))
			rra(a, 1);
	else
		while (!a_sorted(*a))
			ra(a, 1);
}

void	long_sort(t_stack **a)
{
	t_stack	*b;

	if (!*a)
		return ;
	if ((*a)->next == NULL)
		return ;
	b = NULL;
	if (stack_len(*a) >= 500)
		push_a(a, &b, 100);
	else
		push_a(a, &b, 20);
	push_b(a, &b);
}
