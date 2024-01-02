/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:57:04 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/02 16:57:15 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "push_swap.h"

#include "ft_printf.h"

static void	sort_stack(t_stack *a, t_stack *b);
int			chunk_size_formula(int size);

int	main(int argc, char **argv)
{
	t_stack			a;
	t_stack			b;
	t_op			*op_list;

	if (argc == 1)
		return (0);
	init_stacks(&a, &b, &op_list);
	if (!check_argv(argv + 1))
		free_and_exit(&a, &b, true);
	parse_argv(argv + 1, &a);
	if (!a.size)
		free_and_exit(&a, &b, true);
	if (is_stack_sorted(a.head, a.size))
		free_and_exit(&a, &b, false);
	a.sister = &b.head;
	b.sister = &a.head;
	sort_stack(&a, &b);
	//ft_dprintf(2, "<><><><><><><><><><><><><><><><><><><><><><><>");
	free_and_exit(&a, &b, false);
}

void	insert_sort_b_to_a(t_stack *a, t_stack *b);
void	sort_top_three_a(t_stack *stack);

static void	sort_stack(t_stack *a, t_stack *b)
{
	int		chunk;

	set_index(a);
	if (a->size == 2)
		sort_two_elements(a);
	else if (a->size == 3)
		sort_three_elements(a);
	else if (a->size <= 5)
		sort_up_to_five(a, b);
	else
	{
		chunk = chunk_size_formula(a->size);
		korean_sort(a, b, chunk);
		sort_three_elements(a);
		//median_presort(a, b, 0, a->size);
		insert_sort_b_to_a(a, b);
	}
}

void	free_and_exit(t_stack *a, t_stack *b, bool error)
{
	if (a)
	{
		op_clear(a->operations);
		clear_stack(a->head);	
	}
	if (b)
	{
		op_clear(b->operations);
		clear_stack(b->head);
	}
	if (error)
		write(2, "Error\n", 6);
	exit(error);
}

int	chunk_size_formula(int size)
{
	double	chunk;

	chunk = 0.000000053 * size * size + 0.03 * size + 14.5;
	return (chunk);
}
