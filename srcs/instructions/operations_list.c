/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 07:51:53 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/02 22:02:42 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_op	*op_new(enum e_operation i)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	if (!new)
		return (NULL);
	new->op = i;
	new->next = NULL;
	return (new);
}

void	op_add_back(t_op **list, t_op *new)
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
