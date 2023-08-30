/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:36:48 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/22 05:38:19 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

void	clear_stack(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

void	print_stack(t_stack *a)
{
	while (a)
	{
		ft_printf("%d\n", a->value);
		a = a->next;
	}
}

void	print_ops(t_op *op)
{
	while (op)
	{
		ft_printf("%s", op->str);
		op = op->next;
	}
}

int	push_op(t_op **op, char *str)
{
	t_op	*new;
	t_op	*tmp;
	int		error;

	error = 0;
	new = (t_op *)malloc(sizeof(t_op));
	if (!new)
		error = 1;
	if (!error)
	{
		new->str = str;
		new->next = NULL;
		if (!*op)
			*op = new;
		else
		{
			tmp = *op;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
	return (error);
}
