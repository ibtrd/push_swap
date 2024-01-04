/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:02:44 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/04 09:14:41 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "libft.h"

static void	check_input(char *input, t_stack *a, t_stack *b);
static void	apply_operation(t_opid i, t_stack *a, t_stack *b);

void	read_instructions(t_stack *a, t_stack *b)
{
	char	buffer[5];
	int		rd;

	rd = 42;
	while (rd != 0)
	{
		rd = read(0, buffer, 4);
		if (rd == -1)
			free_and_exit(a, true);
		buffer[rd] = '\0';
		check_input(buffer, a, b);
	}
}

static void	check_input(char *input, t_stack *a, t_stack *b)
{
	static const char	*str[] = {
		"sa\n", "sb\n", "ss\n",
		"pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n",
		"rra\n", "rrb\n", "rrr\n"};
	t_opid				i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp(input, str[i]))
			apply_operation(i, a, b);
		i++;
	}
}

static void	apply_operation(t_opid i, t_stack *a, t_stack *b)
{
	if (i == SWAP_A)
		swap(a, NULL);
	else if (i == SWAP_B)
		swap(NULL, b);
	else if (i == SWAP_AB)
		swap(a, b);
	else if (i == PUSH_A)
		push(b, a);
	else if (i == PUSH_B)
		push(a, b);
	else if (i == ROTATE_A)
		rotate(a, NULL);
	else if (i == ROTATE_B)
		rotate(NULL, b);
	else if (i == ROTATE_AB)
		rotate(a, b);
	else if (i == REVERSE_ROTATE_A)
		reverse_rotate(a, NULL);
	else if (i == REVERSE_ROTATE_B)
		reverse_rotate(NULL, b);
	else if (i == REVERSE_ROTATE_AB)
		reverse_rotate(a, b);
}
