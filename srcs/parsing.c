/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:59:05 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/04 05:21:40 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
#include "libft.h"

int	check_argv(char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) \
				&& !ft_ischarset(argv[i][j], SEP_AND_SIGN))
				return (0);
			if (ft_ischarset(argv[i][j], SIGN) \
				&& (!ft_isdigit(argv[i][j + 1]) \
				|| (j != 0 && !ft_ischarset(argv[i][j - 1], SEP))))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	parse_one_argument(char *str, t_stack *a);
static int	get_value(char *str, t_stack *a);
static int	is_duplicate_value(t_stack *a, int value);

void	parse_argv(char **argv, t_stack *a)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		parse_one_argument(argv[i], a);
		i++;
	}
}

static void	parse_one_argument(char *str, t_stack *a)
{
	int		i;
	int		value;

	i = 0;
	while (str[i])
	{
		while (ft_ischarset(str[i], SEP))
			i++;
		if (str[i])
		{
			value = get_value(str + i, a);
			if (is_duplicate_value(a, value))
				free_and_exit(a, true);
			add_to_stack(&(a->head), value);
			a->size += 1;
		}
		while (str[i] && !ft_ischarset(str[i], SEP))
			i++;
	}
}

static int	get_value(char *str, t_stack *a)
{
	int		i;
	int		nb;
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
		if (sign == 1 && (INT_MAX / 10 < nb \
			|| 10 * nb > INT_MAX - (str[i] - 48)))
			free_and_exit(a, true);
		if (sign == -1 && (INT_MIN / 10 > -nb \
			|| 10 * -nb < INT_MIN + (str[i] - 48)))
			free_and_exit(a, true);
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * sign);
}

static int	is_duplicate_value(t_stack *a, int value)
{
	t_node	*curr;

	if (!a->head)
		return (0);
	curr = a->head;
	while (1)
	{
		if (value == curr->value)
			return (1);
		curr = curr->next;
		if (curr == a->head)
			return (0);
	}
}
