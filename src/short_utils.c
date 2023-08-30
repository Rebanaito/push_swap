/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 06:43:42 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/20 01:32:16 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

void	line_up_and_push(t_stack **a, t_stack **b)
{
	if (!finish_up_b(*b))
		while (!b_sorted(*b))
			rrb(b, 1);
	else
		while (!b_sorted(*b))
			rb(b, 1);
	while (*b)
		pa(a, b, 1);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	int	closest;
	int	top;

	if (!*a)
		line_up_and_push(a, b);
	else
	{
		closest = a_closest((*b)->value, *a);
		top = top_to_closest(closest, *a);
		if (top < stack_len(*a) - top)
			while (top--)
				ra(a, 1);
		else
		{
			top = stack_len(*a) - top;
			while (top--)
				rra(a, 1);
		}
		pa(a, b, 1);
	}
}

int	a_closest(int b, t_stack *a)
{
	int	closest;

	closest = a->value;
	a = a->next;
	while (a)
	{
		if (closest < b && a->value >= b)
			closest = a->value;
		else if (closest < b && a->value < b)
		{
			if (b - a->value > b - closest)
				closest = a->value;
		}
		else if (closest >= b && a->value >= b)
		{
			if (a->value - b < closest - b)
				closest = a->value;
		}
		a = a->next;
	}
	return (closest);
}

int	b_closest(int a, t_stack *b)
{
	int	closest;

	closest = b->value;
	b = b->next;
	while (b)
	{
		if (closest >= a && b->value < a)
			closest = b->value;
		else if (closest > a && b->value > a)
		{
			if (b->value - a > closest - a)
				closest = b->value;
		}
		else if (closest <= a && b->value < a)
		{
			if (a - b->value < a - closest)
				closest = b->value;
		}
		b = b->next;
	}
	return (closest);
}
