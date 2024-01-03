/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:47:01 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/03 16:52:23 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_op	*count_rotations(t_op *curr, t_rotations *counter);
static void	cancel_opposites_rotations(t_rotations *counter);
static void	merge_dual_rotations(t_rotations *counter);
static void	print_rotations(t_rotations *counter);


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

static t_op	*count_rotations(t_op *curr, t_rotations *counter)
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

static void	cancel_opposites_rotations(t_rotations *counter)
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

static void	merge_dual_rotations(t_rotations *counter)
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

static void	print_rotations(t_rotations *counter)
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
