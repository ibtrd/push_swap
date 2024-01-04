/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 07:51:53 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/04 05:30:26 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static t_op	*op_new(t_opid i);
static void	op_add_back(t_op **list, t_op *new);

void	operation_to_list(t_stack *stack, t_opid i)
{
	t_op	*new;

	new = op_new(i);
	if (!new)
		free_and_exit(stack, true);
	op_add_back(stack->operations, new);
}

static t_op	*op_new(t_opid i)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	if (!new)
		return (NULL);
	new->op = i;
	new->next = NULL;
	return (new);
}

static void	op_add_back(t_op **list, t_op *new)
{
	static t_op	*tail = NULL;

	if (!*list)
	{
		*list = new;
		tail = new;
	}
	else
	{
		tail->next = new;
		tail = new;
	}
}

void	op_clear(t_op **list)
{
	t_op	*temp;

	while (*list)
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
}
