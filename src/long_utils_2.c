/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 07:27:19 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/22 01:51:06 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

int	is_nums(int num, int nums[], int size)
{
	int	i;

	i = 0;
	while (i < size)
		if (nums[i++] == num)
			return (1);
	return (0);
}

int	a_closest_chunk(int b, t_stack *a, int nums[], int size)
{
	int	closest;

	closest = a->value;
	a = a->next;
	while (a)
	{
		if (closest < b && a->value >= b && is_nums(a->value, nums, size))
			closest = a->value;
		else if (closest < b && a->value < b)
		{
			if (b - a->value > b - closest && is_nums(a->value, nums, size))
				closest = a->value;
		}
		else if (closest >= b && a->value >= b)
		{
			if (a->value - b < closest - b && is_nums(a->value, nums, size))
				closest = a->value;
		}
		a = a->next;
	}
	return (closest);
}

int	b_closest_chunk(int a, t_stack *b, int nums[])
{
	long	closest;
	int		flag;

	closest = 2147483648;
	flag = 0;
	while (b)
	{
		if (!flag && (b->value == nums[0]))
			flag = 1;
		else if (flag && b->value == nums[1])
			flag = 0;
		else if (flag)
			(void)flag;
		else if (closest == 2147483648)
			closest = b->value;
		else if (closest >= a && b->value < a)
			closest = b->value;
		else if (closest > a && b->value > a && b->value - a > closest - a)
			closest = b->value;
		else if (closest <= a && b->value < a && a - b->value < a - closest)
			closest = b->value;
		b = b->next;
	}
	return ((int)closest);
}

static void	norm(t_stack **p, int value, t_stack *b, int nums[])
{
	while (*p)
	{
		if ((*p)->value == b_closest_chunk(value, b, nums))
			break ;
		*p = (*p)->next;
	}
}

void	best_route_chunk(t_stack **a, t_stack **b, int nums[])
{
	t_stack	*p;
	t_stack	*v;
	int		a_best;
	int		b_best;

	a_best = -2147483648;
	b_best = -2147483648;
	v = *a;
	while (v)
	{
		p = *b;
		if (b_closest_chunk(v->value, *b, nums) > v->value)
			while (p->value != nums[0])
				p = p->next;
		else
			norm(&p, v->value, *b, nums);
		comparison(&a_best, &b_best,
			where_a(v, p, stack_len(*a) - stack_len(v),
				stack_len(*b) - stack_len(p)),
			where_b(v, p, stack_len(*a) - stack_len(v),
				stack_len(*b) - stack_len(p)));
		v = v->next;
	}
	move_stacks(a, b, a_best, b_best);
}
