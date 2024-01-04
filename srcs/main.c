/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:57:04 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/04 05:21:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

static void	sort_stack(t_stack *a, t_stack *b);
static int	chunk_size_formula(int size);

int	main(int argc, char **argv)
{
	t_stack			a;
	t_stack			b;
	t_op			*op_list;

	if (argc == 1)
		return (0);
	init_stacks(&a, &b, &op_list);
	if (!check_argv(argv + 1))
		free_and_exit(&a, true);
	parse_argv(argv + 1, &a);
	if (!a.size)
		free_and_exit(&a, true);
	if (is_stack_sorted(a.head, a.size))
		free_and_exit(&a, false);
	a.sister = &b.head;
	b.sister = &a.head;
	sort_stack(&a, &b);
	if (!FORCEPRINT)
		simplify_operations(&a);
	free_and_exit(&a, false);
}

static void	sort_stack(t_stack *a, t_stack *b)
{
	set_index(a);
	if (a->size == 2)
		sort_two_elements(a);
	else if (a->size == 3)
		sort_three_elements(a);
	else
	{
		progressive_presort(a, b, chunk_size_formula(a->size));
		sort_three_elements(a);
		insert_biggest_sort(a, b);
	}
}

static int	chunk_size_formula(int size)
{
	double	chunk;

	chunk = 0.000000053 * size * size + 0.03 * size + 14.5;
	return (chunk);
}

void	free_and_exit(t_stack *stack, bool error)
{
	op_clear(stack->operations);
	clear_stack(stack->head);
	clear_stack(*(stack->sister));
	if (error)
		write(STDERR_FILENO, "Error\n", 6);
	exit(error);
}
