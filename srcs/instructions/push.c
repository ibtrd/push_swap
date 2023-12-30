/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:34:15 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/29 23:25:29 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	instruction_push(t_node **from, t_node **to);

void	pa(t_stack *a, t_stack *b)
{
	instruction_push(&b->head, &a->head);
	a->size++;
	b->size--;
	if (!b->size)
		b->head = NULL;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	instruction_push(&a->head, &b->head);
	a->size--;
	if (!a->size)
		a->head = NULL;
	b->size++;
	write(1, "pb\n", 3);
}

static void	instruction_push(t_node **from, t_node **to)
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
