/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:35:13 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/31 05:51:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	instruction_r(t_node **head);

void	rotate(t_stack *a, t_stack *b, bool print)
{
	if (a)
		instruction_r(&a->head);
	if (b)
		instruction_r(&b->head);
	if (print && a && b)
		write(STDOUT_FILENO, "rr\n", 3);
	else if (print && a)
		write(STDOUT_FILENO, "ra\n", 3);
	else if (print && b)
		write(STDOUT_FILENO, "rb\n", 3);
}

static void	instruction_r(t_node **head)
{
	if (*head)
		*head = (*head)->next;
}
