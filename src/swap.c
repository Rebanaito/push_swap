/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:33:46 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/22 05:21:34 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

void	sa(t_stack **a, int print)
{
	t_stack	*tmp;

	if (stack_size(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int print)
{
	t_stack	*tmp;

	if (stack_size(*b) < 2)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (stack_size(*a) < 2 && stack_size(*b) < 2)
		return ;
	if (stack_size(*a) > 1)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
	if (stack_size(*b) > 1)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
	}
	if (print)
		write(1, "ss\n", 3);
}
