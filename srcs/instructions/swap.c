/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:35:37 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/31 08:49:59 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	instruction_s(t_node *head);

void	swap(t_stack *a, t_stack *b, bool print)
{
	if (a)
		instruction_s(a->head);
	if (b)
		instruction_s(b->head);
	if (print && a && b)
		write(STDOUT_FILENO, "ss\n", 3);
	else if (print && a)
		write(STDOUT_FILENO, "sa\n", 3);
	else if (print && b)
		write(STDOUT_FILENO, "sb\n", 3);
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
