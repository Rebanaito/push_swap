/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 04:07:25 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/22 05:37:07 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

int	a_sorted(t_stack *a)
{
	int	prev;

	if (!a)
		return (1);
	prev = a->value;
	a = a->next;
	while (a)
	{
		if (a->value < prev)
			return (0);
		prev = a->value;
		a = a->next;
	}
	return (1);
}

int	b_sorted(t_stack *b)
{
	int	prev;

	if (!b)
		return (1);
	prev = b->value;
	b = b->next;
	while (b)
	{
		if (b->value > prev)
			return (0);
		prev = b->value;
		b = b->next;
	}
	return (1);
}

int	bottom(t_stack *a)
{
	while (a->next)
		a = a->next;
	return (a->value);
}

int	stack_len(t_stack *a)
{
	int	count;

	if (!a)
		return (0);
	count = 0;
	while (a)
	{
		a = a->next;
		count++;
	}
	return (count);
}
