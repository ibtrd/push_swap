/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:57:04 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/31 21:36:16 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "push_swap.h"

static void	sort_stack(t_stack *a, t_stack *b);
// static int	chunck_size_formula(int size);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	init_stacks(&a, &b);
	if (!check_argv(argv + 1))
		free_and_exit(&a, &b, true);
	parse_argv(argv + 1, &a);
	if (!a.size)
		free_and_exit(&a, &b, true);
	if (is_stack_sorted(a.head))
		free_and_exit(&a, &b, false);
	sort_stack(&a, &b);
	#include "ft_printf.h"
	ft_dprintf(2, "<><><><><><><><><><><><><><><><><><><><><><><>");
	free_and_exit(&a, &b, false);
}

void	korean_sort_b_to_a(t_stack *a, t_stack *b);

static void	sort_stack(t_stack *a, t_stack *b)
{
	// int		chunck;

	set_index(a);
	if (a->size == 2)
		sort_two_elements(a);
	else if (a->size == 3)
		sort_three_elements(a);
	else if (a->size <= 5)
		sort_up_to_five(a, b);
	else
	{
		median_presort(a, b, 0, a->size);
		korean_sort_b_to_a(a, b);
	}
}

// static int	chunck_size_formula(int size)
// {
// 	double	chunck;

// 	chunck = 0.000000053 * size * size + 0.03 * size + 14.5;
// 	return (chunck);
// }

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
