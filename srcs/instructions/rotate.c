/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:35:13 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/29 01:35:15 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	instruction_rotate(t_node **head);

void	ra(t_stacks *stacks)
{
	instruction_rotate(&stacks->head_a);
	write(1, "ra\n", 3);
}

void	rb(t_stacks *stacks)
{
	instruction_rotate(&stacks->head_b);
	write(1, "rb\n", 3);
}

void	rr(t_stacks *stacks)
{
	instruction_rotate(&stacks->head_a);
	instruction_rotate(&stacks->head_b);
	write(1, "rr\n", 3);
}

static void	instruction_rotate(t_node **head)
{
	if (*head)
		*head = (*head)->next;
}
