/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:35:13 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/04 09:21:47 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	instruction_r(t_node **head);

void	rotate(t_stack *a, t_stack *b)
{
	if (a)
		instruction_r(&a->head);
	if (b)
		instruction_r(&b->head);
}

static void	instruction_r(t_node **head)
{
	if (*head)
		*head = (*head)->next;
}
