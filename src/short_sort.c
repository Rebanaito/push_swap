/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 04:02:46 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/20 01:34:17 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

void	rotate_a_and_b(t_stack **a, t_stack **b)
{
	if (stack_len(*b) > 2)
	{
		if (bottom(*b) > (*b)->value && bottom(*b) < bottom(*a))
			rrr(a, b, 1);
		else
			rra(a, 1);
	}
	else
		rra(a, 1);
}

void	rotate_b_and_push(t_stack **a, t_stack **b)
{
	int	closest;
	int	top;

	closest = b_closest((*a)->value, *b);
	top = top_to_closest(closest, *b);
	if (top < stack_len(*b) - top)
		while (top--)
			rb(b, 1);
	else
	{
		top = stack_len(*b) - top;
		while (top--)
			rrb(b, 1);
	}
	pb(a, b, 1);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	if (stack_len(*a) > 2 && a_sorted((*a)->next) && bottom(*a) < (*a)->value)
		ra(a, 1);
	else if (((*a)->next)->value < (*a)->value)
		sa(a, 1);
	else if (bottom(*a) < (*a)->value)
		rotate_a_and_b(a, b);
	else if (!stack_len(*b))
		pb(a, b, 1);
	else if (stack_len(*b) == 1)
	{
		pb(a, b, 1);
		if ((*b)->value < ((*b)->next)->value)
		{
			if (((*a)->next)->value < (*a)->value)
				ss(a, b, 1);
			else
				sb(b, 1);
		}
	}
	else
		rotate_b_and_push(a, b);
}

void	short_sort(t_stack **a)
{
	t_stack	*b;

	if (!*a)
		return ;
	if ((*a)->next == NULL)
		return ;
	b = NULL;
	while (!a_sorted(*a))
		push_to_b(a, &b);
	while (b)
		push_to_a(a, &b);
	if (!finish_up(*a))
		while (!a_sorted(*a))
			rra(a, 1);
	else
		while (!a_sorted(*a))
			ra(a, 1);
}
