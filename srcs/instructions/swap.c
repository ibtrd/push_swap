/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:35:37 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/29 23:27:23 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	instruction_swap(t_node *head);

void	sa(t_stack *a)
{
	instruction_swap(a->head);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	instruction_swap(b->head);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	instruction_swap(a->head);
	instruction_swap(b->head);
	write(1, "ss\n", 3);
}

static void	instruction_swap(t_node *head)
{
	int	temp;

	if (head && head->next)
	{
		temp = head->value;
		head->value = head->next->value;
		head->next->value = temp;
	}
}
