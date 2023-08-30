/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 01:53:26 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/22 05:42:25 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

void	read_operations(t_op **op)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (push_op(op, line))
		{
			free(line);
			break ;
		}
		line = get_next_line(0);
	}
}

int	execute_moves(t_stack **a, t_stack **b, t_op *op)
{
	if (!ft_strcmp(op->str, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(op->str, "pb\n"))
		pb(a, b, 0);
	else if (!ft_strcmp(op->str, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(op->str, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(op->str, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(op->str, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(op->str, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(op->str, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(op->str, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(op->str, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(op->str, "rrr\n"))
		rrr(a, b, 0);
	else
		return (1);
	return (0);
}

int	apply_operations(t_stack **a, t_stack **b, t_op *op)
{
	while (op)
	{
		if (execute_moves(a, b, op))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		op = op->next;
	}
	return (0);
}

void	clear_operations(t_op **op)
{
	t_op	*tmp;

	while (*op)
	{
		tmp = *op;
		*op = (*op)->next;
		free(tmp->str);
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_op	*op;

	a = NULL;
	b = NULL;
	op = NULL;
	if (input(argc, argv, &a))
	{
		read_operations(&op);
		if (!apply_operations(&a, &b, op))
		{
			if (a_sorted(a) && !b)
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
		}
		clear_operations(&op);
	}
	clear_stack(&a);
	return (0);
}
