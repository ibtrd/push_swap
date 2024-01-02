/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:38:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/02 00:08:02 by ibertran         ###   ########lyon.fr   */
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

int	is_stack_sorted(t_node *head, size_t size)
{
	t_node	*curr;
	size_t	i;

	curr = head;
	i = 0;
	while (i < size)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	rotation_control(t_stack *a, t_stack *b, int control, bool print)
{
	if (control < 0)
	{
		if (a && b)
			reverse_rotate(a, b, print);
		else if (a)
			reverse_rotate(a, NULL, print);
		else if (b)
			reverse_rotate(NULL, b, print);
	}
	else
	{
		if (a && b)
			rotate(a, b, print);
		else if (a)
			rotate(a, NULL, print);
		else if (b)
			rotate(NULL, b, print);
	}
}