/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:35:37 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/05 02:30:28 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

	#include <stdio.h>

static void	instruction_s(t_node *head);

void	swap(t_stack *a, t_stack *b)
{
	if (a)
		instruction_s(a->head);
	if (b)
		instruction_s(b->head);
}

static void	instruction_s(t_node *head)
{
	int	temp;

	if (head && head->next)
	{
		temp = head->value;
		head->value = head->next->value;
		head->next->value = temp;
	}
}
