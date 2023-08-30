/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 03:10:52 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/22 05:20:59 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

int	push(t_stack **a, int value)
{
	t_stack	*new;
	int		error;

	error = 0;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		error = 1;
	if (!error)
	{
		new->value = value;
		if (*a)
			new->next = (*a);
		else
			new->next = NULL;
		*a = new;
	}
	return (error);
}

t_stack	*pop(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	return (tmp);
}

int	stack_size(t_stack *a)
{
	int	count;

	count = 0;
	while (a)
	{
		a = a->next;
		count++;
	}
	return (count);
}

void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (!stack_size(*b))
		return ;
	tmp = pop(b);
	tmp->next = *a;
	*a = tmp;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (!stack_size(*a))
		return ;
	tmp = pop(a);
	tmp->next = *b;
	*b = tmp;
	if (print)
		write(1, "pb\n", 3);
}
