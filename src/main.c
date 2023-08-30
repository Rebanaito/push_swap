/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 02:40:31 by revanite          #+#    #+#             */
/*   Updated: 2023/06/22 11:14:22 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (input(argc, argv, &a))
	{
		if (stack_len(a) <= 50)
			short_sort(&a);
		else
			long_sort(&a);
	}
	clear_stack(&a);
	return (0);
}
