/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:38:00 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/31 18:37:27 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

void	init_stacks(t_stack *a, t_stack *b)
{
	a->id = 'a';
	a->head = NULL;
	a->size = 0;
	b->id = 'b';
	b->head = NULL;
	b->size = 0;
}

void	add_to_stack(t_node **head, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit(999);
	new->value = value;
	if (!*head)
	{
		new->next = new;
		new->prev = new;
		*head = new;
	}
	else
	{
		new->next = *head;
		new->prev = (*head)->prev;
		(*head)->prev->next = new;
		if ((*head)->next == *head)
			(*head)->next = new;
		(*head)->prev = new;
	}
}


void	clear_stack(t_node *head)
{
	t_node	*temp;

	if (!head)
		return ;
	head->prev->next = NULL;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	is_stack_sorted(t_node *head)
{
	t_node	*curr;

	curr = head;
	while (curr->next != head)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}
