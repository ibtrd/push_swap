/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:34:47 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/29 01:34:54 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	instruction_reverse_rotate(t_node **head);

void	rra(t_stacks *stacks)
{
	instruction_reverse_rotate(&stacks->head_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *stacks)
{
	instruction_reverse_rotate(&stacks->head_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stacks)
{
	instruction_reverse_rotate(&stacks->head_a);
	instruction_reverse_rotate(&stacks->head_b);
	write(1, "rrr\n", 4);
}

static void	instruction_reverse_rotate(t_node **head)
{
	if (*head)
		*head = (*head)->prev;
}
