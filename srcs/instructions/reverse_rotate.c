/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:34:47 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/29 23:31:25 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	instruction_reverse_rotate(t_node **head);

void	rra(t_stack *a)
{
	instruction_reverse_rotate(&a->head);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	instruction_reverse_rotate(&b->head);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	instruction_reverse_rotate(&a->head);
	instruction_reverse_rotate(&b->head);
	write(1, "rrr\n", 4);
}

static void	instruction_reverse_rotate(t_node **head)
{
	if (*head)
		*head = (*head)->prev;
}
