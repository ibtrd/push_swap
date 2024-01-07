/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:57:04 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/07 09:01:38 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

static void	sort_stack(t_stack *a, t_stack *b);

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
	if (a.size == 1 || is_stack_sorted(a.head))
		free_and_exit(&a, false);
	sort_stack(&a, &b);
	if (!FORCEPRINT)
		simplify_operations(&a);
	free_and_exit(&a, false);
}

static void	sort_stack(t_stack *a, t_stack *b)
{
	double	chunk;

	chunk = 0.000000053 * a->size * a->size + 0.03 * a->size + 14.5;
	set_index(a);
	progressive_presort(a, b, chunk);
	insert_biggest_sort(a, b);
}

void	free_and_exit(t_stack *stack, bool error)
{
	op_clear(stack->operations);
	clear_stack(stack->head);
	clear_stack(stack->sister->head);
	if (error)
		write(STDERR_FILENO, "Error\n", 6);
	exit(error);
}
