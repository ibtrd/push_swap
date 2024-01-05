/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progressive_presort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:53:53 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/05 05:12:30 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	presort_push_top(t_stack *a, t_stack *b, int *min, int *direction);
static void	presort_push_bot(t_stack *a, t_stack *b, int *min, int *direction);
static int	presort_direction(t_stack *a, int range);

void	progressive_presort(t_stack *a, t_stack *b, int chunk)
{
	int	range[2];
	int	direction;

	presort_init(range, a->size, &direction);
	direction = presort_direction(a, range[0] + chunk);
	while (a->size > 3)
	{
		if (a->head->index < range[0])
			presort_push_top(a, b, range, &direction);
		else if (a->head->index < range[0] + chunk && a->head->index < range[1])
			presort_push_bot(a, b, range, &direction);
		else
		{
			if (direction == 0)
				direction = presort_direction(a, range[0] + chunk);
			rotation_control(a, NULL, direction);
		}
	}
}

static void	presort_push_top(t_stack *a, t_stack *b, int *range, int *direction)
{
	push(a, b);
	(*range)++;
	*direction = 0;
}

static void	presort_push_bot(t_stack *a, t_stack *b, int *range, int *direction)
{
	push(a, b);
	rotate(NULL, b);
	(*range)++;
	*direction = 0;
}

static int	presort_direction(t_stack *a, int range)
{
	t_node	*curr;
	int		i;

	curr = a->head;
	i = 0;
	while (i < a->size && curr->index > range)
	{
		i++;
		curr = curr->next;
	}
	if (i < a->size / 2)
		return (1);
	return (-1);
}
