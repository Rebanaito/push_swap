/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 07:08:01 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/20 01:31:30 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

static void	uu(t_stack **a, t_stack **b, int a_best, int b_best)
{
	while (a_best && b_best)
	{
		rr(a, b, 1);
		a_best--;
		b_best--;
	}
	while (a_best--)
		ra(a, 1);
	while (b_best--)
		rb(b, 1);
}

static void	dd(t_stack **a, t_stack **b, int a_best, int b_best)
{
	while (a_best < 0 && b_best < 0)
	{
		rrr(a, b, 1);
		a_best++;
		b_best++;
	}
	while (a_best++ < 0)
		rra(a, 1);
	while (b_best++ < 0)
		rrb(b, 1);
}

static void	ud(t_stack **a, t_stack **b, int a_best, int b_best)
{
	while (a_best--)
		ra(a, 1);
	while (b_best++ < 0)
		rrb(b, 1);
}

static void	du(t_stack **a, t_stack **b, int a_best, int b_best)
{
	while (a_best++ < 0)
		rra(a, 1);
	while (b_best--)
		rb(b, 1);
}

void	move_stacks(t_stack **a, t_stack **b, int a_best, int b_best)
{
	if (a_best >= 0 && b_best >= 0)
		uu(a, b, a_best, b_best);
	else if (a_best < 0 && b_best < 0)
		dd(a, b, a_best, b_best);
	else if (a_best >= 0)
		ud(a, b, a_best, b_best);
	else
		du(a, b, a_best, b_best);
}
