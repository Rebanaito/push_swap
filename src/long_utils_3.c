/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 07:34:44 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/22 11:12:49 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

static void	store_nums(t_stack *b, int nums[])
{
	nums[0] = b->value;
	nums[1] = bottom(b);
}

int	has_nums(t_stack *b, int nums[])
{
	if (b->value == nums[0] && bottom(b) == nums[1])
		return (0);
	return (1);
}

void	last_chunk(t_stack **a, t_stack **b, int size)
{
	int	nums[2];

	store_nums(*b, nums);
	while (!a_sorted(*a))
	{
		if (has_nums(*b, nums))
			best_route_chunk(a, b, nums);
		pb(a, b, 1);
	}
	while (bottom(*b) != nums[1])
		rrb(b, 1);
	while (stack_len(*a) != size)
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
