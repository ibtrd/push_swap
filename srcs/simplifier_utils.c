/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplifier_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:47:42 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/04 05:30:40 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_counter(t_rotations *counter)
{
	counter->ra = 0;
	counter->rb = 0;
	counter->rr = 0;
	counter->rra = 0;
	counter->rrb = 0;
	counter->rrr = 0;
}

int	is_rotation(t_opid i)
{
	if (i >= ROTATE_A && i <= REVERSE_ROTATE_AB)
		return (1);
	return (0);
}
