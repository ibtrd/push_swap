/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 03:27:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/06 10:30:44 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

void	set_index(t_stack *stack)
{
	t_node	*curr;
	t_node	*cmp;
	int		i;
	int		j;
	int		index;

	curr = stack->head;
	index = 0;
	j = 0;
	while (j++ < stack->size)
	{
		i = 0;
		index = 0;
		cmp = stack->head;
		while (i++ < stack->size)
		{
			if (cmp->value < curr->value)
				index++;
			cmp = cmp->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}

t_node	*get_biggest_node(t_stack *stack)
{
	t_node	*curr;
	t_node	*biggest;
	int		i;

	curr = stack->head;
	biggest = curr;
	i = 0;
	while (i++ < stack->size)
	{
		if (curr->index > biggest->index)
			biggest = curr;
		curr = curr->next;
	}
	return (biggest);
}

t_node	*get_single_node(t_stack *stack, int target)
{
	t_node	*curr;
	int		i;

	curr = stack->head;
	i = 0;
	while (i++ < stack->size)
	{
		if (curr->index == target)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

int	single_node_distance(t_node *head, t_node *target, int size)
{
	t_node	*rot;
	t_node	*rev;
	int		i;

	i = 0;
	rot = head;
	rev = head;
	while (i < size)
	{
		if (rev == target)
			return (-i);
		if (rot == target)
			return (i);
		rot = rot->next;
		rev = rev->prev;
		i++;
	}
	return (0);
}
