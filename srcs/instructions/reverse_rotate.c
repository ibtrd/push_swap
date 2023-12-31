/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:34:47 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/31 05:04:34 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	instruction_rr(t_node **head);

void	reverse_rotate(t_stack *a, t_stack *b, bool print)
{
	if (a)
		instruction_rr(&a->head);
	if (b)
		instruction_rr(&b->head);
	if (print && a && b)
		write(STDOUT_FILENO, "rrr\n", 4);
	else if (print && a)
		write(STDOUT_FILENO, "rra\n", 4);
	else if (print && b)
		write(STDOUT_FILENO, "rrb\n", 4);
}

static void	instruction_rr(t_node **head)
{
	if (*head)
		*head = (*head)->prev;
}
