/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 07:20:06 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/19 07:20:15 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

int	tot(int i, int j)
{
	int	total;

	if (i >= 0 && j >= 0)
	{
		total = j;
		if (i > j)
			total = i;
	}
	else if (i < 0 && j < 0)
	{
		total = j;
		if (i < j)
			total = i;
		total *= -1;
	}
	else if (i >= 0 && j < 0)
		total = i - j;
	else
		total = j - i;
	return (total);
}

void	comparison(int *a_best, int *b_best, int i, int j)
{
	int	total;
	int	best;

	total = tot(i, j);
	best = tot(*a_best, *b_best);
	if ((*a_best == -2147483648 && *b_best == -2147483648)
		|| (total <= best && j * j < *b_best * *b_best))
	{
		*a_best = i;
		*b_best = j;
	}
}

int	where_b(t_stack *a, t_stack *p, int i, int j)
{
	int	uu;
	int	dd;
	int	ud;
	int	du;

	uu = i;
	if (j > i)
		uu = j;
	dd = stack_len(a);
	if (stack_len(p) > stack_len(a))
		dd = stack_len(p);
	ud = i + stack_len(p);
	du = stack_len(a) + j;
	if (uu <= dd && uu <= ud && uu <= du)
		return (j);
	if (dd <= uu && dd <= ud && dd <= du)
		return ((-1) * stack_len(p));
	if (ud <= uu && ud <= dd && ud <= du)
		return ((-1) * stack_len(p));
	if (du <= uu && du <= dd && du <= ud)
		return (j);
	return (0);
}

int	where_a(t_stack *a, t_stack *p, int i, int j)
{
	int	uu;
	int	dd;
	int	ud;
	int	du;

	uu = i;
	if (j > i)
		uu = j;
	dd = stack_len(a);
	if (stack_len(p) > stack_len(a))
		dd = stack_len(p);
	ud = i + stack_len(p);
	du = stack_len(a) + j;
	if (uu <= dd && uu <= ud && uu <= du)
		return (i);
	if (dd <= uu && dd <= ud && dd <= du)
		return ((-1) * (stack_len(a)));
	if (ud <= uu && ud <= dd && ud <= du)
		return (i);
	if (du <= uu && du <= dd && du <= ud)
		return ((-1) * stack_len(a));
	return (0);
}

void	best_route(t_stack *a, t_stack *b, int *a_best, int *b_best)
{
	int		i;
	int		j;
	t_stack	*p;

	i = 0;
	while (a)
	{
		p = b;
		j = 0;
		while (p)
		{
			if (p->value == b_closest(a->value, b))
				break ;
			j++;
			p = p->next;
		}
		comparison(a_best, b_best, where_a(a, b, i, j), where_b(a, b, i, j));
		i++;
		a = a->next;
	}
}
