/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 06:50:16 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/19 06:51:20 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

int	finish_up(t_stack *a)
{
	int	len;
	int	i;
	int	min;

	len = stack_len(a);
	min = a->value;
	a = a->next;
	i = 0;
	while (a)
	{
		if (a->value < min)
			break ;
		i++;
		a = a->next;
	}
	if (i <= len / 2)
		return (1);
	return (0);
}

int	finish_up_b(t_stack *b)
{
	int	len;
	int	i;
	int	max;

	len = stack_len(b);
	max = b->value;
	b = b->next;
	i = 0;
	while (b)
	{
		if (b->value > max)
			break ;
		i++;
		b = b->next;
	}
	if (i <= len / 2)
		return (1);
	return (0);
}

int	top_to_closest(int closest, t_stack *b)
{
	int	count;

	count = 0;
	while (b)
	{
		if (b->value == closest)
			break ;
		b = b->next;
		count++;
	}
	return (count);
}
