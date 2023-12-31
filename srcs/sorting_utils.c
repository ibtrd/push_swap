/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 03:27:00 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/01 00:13:44 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

void	set_index(t_stack *stack)
{
	t_node	*curr;
	t_node	*cmp;
	int		i;

	curr = stack->head;
	while (1)
	{
		i = 0;
		cmp = stack->head;
		while (1)
		{
			if (cmp->value < curr->value)
				i++;
			cmp = cmp->next;
			if (cmp == stack->head)
				break ;
		}
		curr->index = i;
		curr = curr->next;
		if (curr == stack->head)
			break ;
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

t_node	*get_node(t_stack *stack, int target)
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
