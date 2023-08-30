/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:54:28 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/22 05:20:33 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

void	rra(t_stack **a, int print)
{
	t_stack	*tmp;

	if (stack_size(*a) < 2)
		return ;
	tmp = *a;
	while ((tmp->next)->next)
		tmp = tmp->next;
	(tmp->next)->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print)
{
	t_stack	*tmp;

	if (stack_size(*b) < 2)
		return ;
	tmp = *b;
	while ((tmp->next)->next)
		tmp = tmp->next;
	(tmp->next)->next = *b;
	*b = tmp->next;
	tmp->next = NULL;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (stack_size(*a) < 2 && stack_size(*b) < 2)
		return ;
	if (stack_size(*a) > 1)
	{
		tmp = *a;
		while ((tmp->next)->next)
			tmp = tmp->next;
		(tmp->next)->next = *a;
		*a = tmp->next;
		tmp->next = NULL;
	}
	if (stack_size(*b) > 1)
	{
		tmp = *b;
		while ((tmp->next)->next)
			tmp = tmp->next;
		(tmp->next)->next = *b;
		*b = tmp->next;
		tmp->next = NULL;
	}
	if (print)
		write(1, "rrr\n", 4);
}
