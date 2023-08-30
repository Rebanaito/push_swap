/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 03:02:42 by ekolosov          #+#    #+#             */
/*   Updated: 2023/06/10 02:04:52 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

static int	split_to_stack(t_stack **a, char *line);
static int	args_to_stack(t_stack **a, int argc, char **argv);
static int	valid_num(const char *s);
static int	check_duplicates(t_stack *a);

int	input(int argc, char **argv, t_stack **a)
{
	int		error;

	error = 0;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		error = split_to_stack(a, argv[1]);
	else
		error = args_to_stack(a, argc, argv);
	if (!error)
		error = check_duplicates(*a);
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

static int	split_to_stack(t_stack **a, char *line)
{
	char	**split;
	int		error;
	int		i;

	split = ft_split(line, ' ');
	if (!split)
		return (1);
	i = 0;
	error = 0;
	while (split[i] && !error)
		if (!valid_num(split[i++]))
			error = 1;
	if (!error)
	{
		i--;
		while (i >= 0 && !error)
			error = push(a, ft_atoi(split[i--]));
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (error);
}

static int	args_to_stack(t_stack **a, int argc, char **argv)
{
	int	error;
	int	i;

	i = 1;
	error = 0;
	while (i < argc && !error)
		if (!valid_num(argv[i++]))
			error = 1;
	if (!error)
	{
		i--;
		while (i && !error)
			error = push(a, ft_atoi(argv[i--]));
	}
	return (error);
}

static int	valid_num(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '-' && s[i] != '+')
			return (0);
		if ((s[i] == '-' || s[i] == '+') && i)
			return (0);
		i++;
	}
	if (ft_isdigit(*s))
		if (ft_strcmp(s, "2147483647") && ft_strlen(s) >= 10)
			return (0);
	if (*s == '+')
		if (ft_strcmp(s, "+2147483647") && ft_strlen(s) >= 11)
			return (0);
	if (*s == '-')
		if (ft_strcmp(s, "-2147483648") && ft_strlen(s) >= 11)
			return (0);
	return (1);
}

static int	check_duplicates(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;

	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}
