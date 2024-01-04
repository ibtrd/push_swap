/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:35:37 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/04 05:25:10 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	instruction_s(t_node *head);

void	swap(t_stack *a, t_stack *b)
{
	t_opid	i;

	if (a)
		instruction_s(a->head);
	if (b)
		instruction_s(b->head);
	if (a && b)
		i = SWAP_AB;
	else if (a)
		i = SWAP_A;
	else
		i = SWAP_B;
	if (a && FORCEPRINT)
		print_operation(i, a);
	else if (b && FORCEPRINT)
		print_operation(i, a);
	else
	{
		if (a)
			operation_to_list(a, i);
		if (b)
			operation_to_list(b, i);
	}
}

static void	instruction_s(t_node *head)
{
	int	temp;

	if (head && head->next)
	{
		temp = head->value;
		head->value = head->next->value;
		head->next->value = temp;
		temp = head->index;
		head->index = head->next->index;
		head->next->index = temp;
	}
}
