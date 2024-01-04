/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:35:13 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/04 05:29:47 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	instruction_r(t_node **head);

void	rotate(t_stack *a, t_stack *b)
{
	t_opid	i;

	if (a)
		instruction_r(&a->head);
	if (b)
		instruction_r(&b->head);
	if (a && b)
		i = ROTATE_AB;
	else if (a)
		i = ROTATE_A;
	else
		i = ROTATE_B;
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

static void	instruction_r(t_node **head)
{
	if (*head)
		*head = (*head)->next;
}

void	rotation_control(t_stack *a, t_stack *b, int direction)
{
	if (direction < 0)
	{
		if (a && b)
			reverse_rotate(a, b);
		else if (a)
			reverse_rotate(a, NULL);
		else if (b)
			reverse_rotate(NULL, b);
	}
	else
	{
		if (a && b)
			rotate(a, b);
		else if (a)
			rotate(a, NULL);
		else if (b)
			rotate(NULL, b);
	}
}
