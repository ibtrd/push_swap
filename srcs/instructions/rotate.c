/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:35:13 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/02 20:42:18 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	instruction_r(t_node **head);

void	rotate(t_stack *a, t_stack *b)
{
	enum e_operation	i;
	
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
	if (FORCEPRINT)
		print_operation(i);
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
