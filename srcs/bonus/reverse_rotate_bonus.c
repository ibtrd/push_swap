/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:34:47 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/05 00:06:46 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	instruction_rr(t_node **head);

void	reverse_rotate(t_stack *a, t_stack *b)
{
	if (a)
		instruction_rr(&a->head);
	if (b)
		instruction_rr(&b->head);
}

static void	instruction_rr(t_node **head)
{
	if (*head)
		*head = (*head)->prev;
}
