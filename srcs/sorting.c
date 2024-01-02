/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:10:19 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/02 02:54:03 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	sort_two_elements(t_stack *a)
{
	if (a->head->value > a->head->next->value)
		swap(a, NULL, true);
}

void	sort_three_elements(t_stack *a)
{
	t_node	*biggest;

	biggest = get_biggest_node(a);
	if (a->head->index == biggest->index)
		rotate(a, NULL, true);
	else if (a->head->next->index == biggest->index)
		reverse_rotate(a, NULL, true);
	if (a->head->index > a->head->next->index)
		swap(a, NULL, true);
}

// void	sort_top_three_a(t_stack *stack)
// {
// 	if (stack->head->index > stack->head->next->index)
// 		swap(stack, NULL, true);
// 	if (stack->head->next->index > stack->head->next->next->index)
// 	{
// 		rotate(stack, NULL, true);
// 		swap(stack, NULL, true);
// 		reverse_rotate(stack, NULL, true);
// 	}
// 	if (stack->head->index > stack->head->next->index)
// 		swap(stack, NULL, true);
// }

// void	sort_top_three_b(t_stack *a, t_stack *b)
// {
// 	if (b->head->index < b->head->next->index)
// 		swap(NULL, b, true);
// 	push(b, a, true);
// 	if (b->head->index < b->head->next->index)
// 	{
// 		swap(NULL, b, true);
// 		push(b, a, true);
// 		swap(a, b, true);
// 	}
// 	else
// 	push(b, a, true);
// 	}
// }

void	sort_up_to_five(t_stack *a, t_stack *b)
{
	while (b->size <= 1)
	{
		if (a->head->index == 0 || a->head->index == 1)
			push(a, b, true);
		else
			rotate(a, b, true);
	}
	sort_three_elements(a);
	push(b, a, true);
	push(b, a, true);
	if (a->head->index > a->head->next->index)
		swap(a, NULL, true);
}
