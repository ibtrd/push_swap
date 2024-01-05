/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:20:54 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/05 03:06:02 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker_bonus.h"

void	init_stacks(t_stack *a, t_stack *b)
{
	a->id = 'a';
	a->head = NULL;
	a->size = 0;
	a->sister = b;
	b->id = 'b';
	b->head = NULL;
	b->size = 0;
	b->sister = a;
}

void	add_to_stack(t_stack *a, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		free_and_exit(a, true);
	new->value = value;
	if (!a->head)
	{
		new->next = new;
		new->prev = new;
		a->head = new;
	}
	else
	{
		new->next = a->head;
		new->prev = a->head->prev;
		a->head->prev->next = new;
		if (a->head->next == a->head)
			a->head->next = new;
		a->head->prev = new;
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

bool	is_stack_sorted(t_node *head)
{
	t_node	*curr;
	int		i;

	curr = head;
	i = 0;
	while (curr->next != head)
	{
		if (curr->value > curr->next->value)
			return (false);
		curr = curr->next;
	}
	return (true);
}
