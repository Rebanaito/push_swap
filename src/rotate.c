/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:12:17 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/22 05:20:04 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

void	ra(t_stack **a, int print)
{
	t_stack	*tmp;

	if (stack_size(*a) < 2)
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *a;
	*a = (*a)->next;
	tmp = tmp->next;
	tmp->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int print)
{
	t_stack	*tmp;

	if (stack_size(*b) < 2)
		return ;
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *b;
	*b = (*b)->next;
	tmp = tmp->next;
	tmp->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	if (stack_size(*a) < 2 && stack_size(*b) < 2)
		return ;
	if (stack_size(*a) > 1)
		ra(a, 0);
	if (stack_size(*b) > 1)
		rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
}
