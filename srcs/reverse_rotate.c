/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:34:47 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/04 05:03:24 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	instruction_rr(t_node **head);

void	reverse_rotate(t_stack *a, t_stack *b)
{
	enum e_operation	i;

	if (a)
		instruction_rr(&a->head);
	if (b)
		instruction_rr(&b->head);
	if (a && b)
		i = REVERSE_ROTATE_AB;
	else if (a)
		i = REVERSE_ROTATE_A;
	else
		i = REVERSE_ROTATE_B;
	if (a && FORCEPRINT)
		print_operation(i, a);
	else if (b && FORCEPRINT)
		print_operation(i, b);
	else
	{
		if (a)
			operation_to_list(a, i);
		else
			operation_to_list(b, i);
	}
}

static void	instruction_rr(t_node **head)
{
	if (*head)
		*head = (*head)->prev;
}
