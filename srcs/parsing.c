/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:59:05 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/28 16:59:05 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

void	parse_argv(char **argv, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		parse_one(argv[i], stacks);
		i++;
	}
}

void	parse_one(char *str, t_stacks *stacks)
{
	int		i;
	int		value;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			value = get_value(str + i, stacks);
			if (is_duplicate_value(stacks, value))
				free_and_exit(stacks, true);
			add_to_stack(&(stacks->head_a), value);
			stacks->size_a += 1;
		}
		while (str[i] && str[i] != ' ')
			i++;
	}
}

int	get_value(char *str, t_stacks *stacks)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		// if (INT_MAX / nb * 10 + str[i] - 48 )
		nb = nb * 10 + str[i] - 48;
		if ((nb * sign > INT_MAX || nb * sign < INT_MIN))
			free_and_exit(stacks, true);
		i++;
	}
	return (nb * sign);
}


int	is_duplicate_value(t_stacks *stacks, int value)
{
	t_node	*curr;

	if (!stacks->head_a)
		return (0);
	curr = stacks->head_a;
	while (1)
	{
		if (value == curr->value)
			return (1);
		curr = curr->next;
		if (curr == stacks->head_a)
			return (0);
	}
}
