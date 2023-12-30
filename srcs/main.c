/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:57:04 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/30 05:24:38 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "push_swap.h"

static void	sort_stack(t_stack *a);
static int	chunck_size_formula(int size);

void	print_both_stacks(t_stack *a, t_stack *b);

int	main(int argc, char **argv)
{
	t_stack	a;

	if (argc == 1)
		return (0);
	init_stack(&a);
	if (!check_argv(argv + 1))
		free_and_exit(&a, NULL, 1);
	parse_argv(argv + 1, &a);
	if (!a.size)
		free_and_exit(&a, NULL, 1);
	if (is_stack_sorted(a.head))
		free_and_exit(&a, NULL, 0);
	sort_stack(&a);
}

static void	sort_stack(t_stack *a)
{
	t_stack	b;
	int		chunck;

	set_index(a);
	init_stack(&b);
	chunck = chunck_size_formula(a->size);
	if (a->size == 2)
		sort_two_elements(a);
	else if (a->size == 3)
		sort_three_elements(a);
	else if (a->size >= 50)
		korean_sort(a, &b, 30);
	else
		korean_sort(a, &b, 5);
	free_and_exit(a, &b, 0);
}

void	free_and_exit(t_stack *a, t_stack *b, bool error)
{
	if (a)
		clear_stack(a->head);
	if (b)
		clear_stack(b->head);
	if (error)
		write(2, "Error\n", 6);
	exit(error);
}

static int	chunck_size_formula(int size)
{
	double	temp;

	temp = 0.000000053 * size;
	temp = temp * temp + 0.03 * size + 14.5;
	return (temp);
}
