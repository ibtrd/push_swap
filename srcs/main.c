/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:57:04 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/03 16:01:20 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "push_swap.h"

#include "ft_printf.h"

static void	sort_stack(t_stack *a, t_stack *b);
int			chunk_size_formula(int size);
void	simplify_operations(t_op **list);

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
	//ft_dprintf(2, "\n<><><><><><><><><><><><><><><><><><><><><><><>\n");
	//print_operation_list(a.operations);
	simplify_operations(a.operations);
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

t_op	*count_rotations(t_op *curr, t_rotations *counter);
int		is_rotation(enum e_operation i);
void	init_counter(t_rotations *counter);
void	*set_new_operations(t_rotations *counter);
void	merge_dual_rotations(t_rotations *counter);
void	cancel_opposites_rotations(t_rotations *counter);
void	print_rotations(t_rotations *counter);

void	simplify_operations(t_op **list)
{
	t_op		*curr;
	t_rotations	counter;

	curr = *list;
	while (curr)
	{
		if (!is_rotation(curr->op))
		{
			print_operation(curr->op);
			curr = curr->next;
		}
		else
		{
			init_counter(&counter);
			curr = count_rotations(curr, &counter);
			cancel_opposites_rotations(&counter);
			merge_dual_rotations(&counter);
			print_rotations(&counter);
		}
	}
}

void	init_counter(t_rotations *counter)
{
	counter->ra = 0;
	counter->rb = 0;
	counter->rr = 0;
	counter->rra = 0;
	counter->rrb = 0;
	counter->rrr = 0;
}

t_op	*count_rotations(t_op *curr, t_rotations *counter)
{
	while (curr && is_rotation(curr->op))
	{
		if (curr->op == ROTATE_A)
			counter->ra++;
		if (curr->op == ROTATE_B)
			counter->rb++;
		if (curr->op == ROTATE_AB)
			counter->rr++;
		if (curr->op == REVERSE_ROTATE_A)
			counter->rra++;
		if (curr->op == REVERSE_ROTATE_B)
			counter->rrb++;
		if (curr->op == REVERSE_ROTATE_AB)
			counter->rrr++;
		curr = curr->next;
	}
	return (curr);
}

void	cancel_opposites_rotations(t_rotations *counter)
{
	while (counter->ra && counter->rra)
	{
		counter->ra--;
		counter->rra--;
	}
	while (counter->rb && counter->rrb)
	{
		counter->rb--;
		counter->rrb--;
	}
	while (counter->rr && counter->rrr)
	{
		counter->rr--;
		counter->rrr--;
	}
}

void	merge_dual_rotations(t_rotations *counter)
{
	while (counter->ra && counter->rb)
	{
		counter->ra--;
		counter->rb--;
		counter->rr++;
	}
	while (counter->rra && counter->rrb)
	{
		counter->rra--;
		counter->rrb--;
		counter->rrr++;
	}
}

void	print_rotations(t_rotations *counter)
{
	while (counter->rr--)
		print_operation(ROTATE_AB);
	while (counter->ra--)
		print_operation(ROTATE_A);
	while (counter->rb--)
		print_operation(ROTATE_B);
	while (counter->rrr--)
		print_operation(REVERSE_ROTATE_AB);
	while (counter->rra--)
		print_operation(REVERSE_ROTATE_A);
	while (counter->rrb--)
		print_operation(REVERSE_ROTATE_B);
}

int	is_rotation(enum e_operation i)
{
	if (i >= 0 && i <= 4)
		return (0);
	return (1);
}
