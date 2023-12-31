/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:34:15 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/31 21:22:49 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	instruction_p(t_node **from, t_node **to);

void	push(t_stack *from, t_stack *to, bool print)
{
	instruction_p(&from->head, &to->head);
	to->size++;
	from->size--;
	if (!from->size)
		from->head = NULL;
	if (print)
	{
		write(STDOUT_FILENO, "p", 1);
		write(STDOUT_FILENO, &to->id, 1);
		write(STDOUT_FILENO, "\n", 1);
	}
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
