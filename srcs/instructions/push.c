/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:34:15 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/31 04:56:55 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	instruction_p(t_node **from, t_node **to);

void	push_to_a(t_stack *a, t_stack *b, bool print)
{
	instruction_p(&b->head, &a->head);
	a->size++;
	b->size--;
	if (!b->size)
		b->head = NULL;
	if (print)
		write(STDOUT_FILENO, "pa\n", 3);
}

void	push_to_b(t_stack *a, t_stack *b, bool print)
{
	instruction_p(&a->head, &b->head);
	a->size--;
	if (!a->size)
		a->head = NULL;
	b->size++;
	if (print)
		write(STDOUT_FILENO, "pb\n", 3);
}

static void	instruction_p(t_node **from, t_node **to)
{
	t_node	*temp;

	if (!*from)
		return ;
	temp = *from;
	(*from)->prev->next = (*from)->next;
	(*from)->next->prev = (*from)->prev;
	*from = (*from)->next;
	if (!*to)
	{
		temp->prev = temp;
		temp->next = temp;
	}
	else
	{
		temp->prev = (*to)->prev;
		temp->next = *to;
		(*to)->prev->next = temp;
		(*to)->prev = temp;
	}
	*to = temp;
}
