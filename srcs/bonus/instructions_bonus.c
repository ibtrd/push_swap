/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:02:44 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/05 03:20:50 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include "checker_bonus.h"
#include "libft.h"

static int	check_input(char *input, t_stack *a, t_stack *b);
static void	other_operations(t_opid i, t_stack *a, t_stack *b);

void	read_instructions(t_stack *a, t_stack *b)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (check_input(input, a, b) == -1)
		{
			free(input);
			free_and_exit(a, true);
		}
		else
		{
			free(input);
			input = get_next_line(0);
		}
	}
	if (errno)
		free_and_exit(a, true);
}

static int	check_input(char *input, t_stack *a, t_stack *b)
{
	t_opid				i;
	static const char	*str[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp(input, str[i]))
		{
			if (i == PUSH_A)
				push(b, a);
			else if (i == PUSH_B)
				push(a, b);
			else if (ft_ischarset('a', str[i]))
				other_operations(i, a, NULL);
			else if (ft_ischarset('b', str[i]))
				other_operations(i, NULL, b);
			else
				other_operations(i, a, b);
			return (0);
		}
		i++;
	}
	return (-1);
}

static void	other_operations(t_opid i, t_stack *a, t_stack *b)
{
	if (i >= SWAP_A && i <= SWAP_AB)
		swap(a, b);
	else if (i >= ROTATE_A && i <= ROTATE_AB)
		rotate(a, b);
	else if (i >= REVERSE_ROTATE_A && i <= REVERSE_ROTATE_AB)
		reverse_rotate(a, b);
}
