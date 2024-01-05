/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:10:19 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/05 05:31:22 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_elements(t_stack *a)
{
	if (a->head->value > a->head->next->value)
		swap(a, NULL);
}

void	sort_three_elements(t_stack *a)
{
	t_node	*biggest;

	biggest = get_biggest_node(a);
	if (a->head->index == biggest->index)
		rotate(a, NULL);
	else if (a->head->next->index == biggest->index)
		reverse_rotate(a, NULL);
	if (a->head->index > a->head->next->index)
		swap(a, NULL);
}

void	sort_up_to_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->head->index == 0 || a->head->index == 1)
			push(a, b);
		else
			rotate(a, b);
	}
	sort_three_elements(a);
	push(b, a);
	push(b, a);
	if (a->head->index > a->head->next->index)
		swap(a, NULL);
}
