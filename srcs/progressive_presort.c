/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progressive_presort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:53:53 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/04 05:37:23 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	presort_push_top(t_stack *a, t_stack *b, int *rb, int *min);
static void	presort_push_bot(t_stack *a, t_stack *b, int *rb, int *min);
static int	presort_direction(t_stack *a, int range);
static void	presort_rotate(t_stack *a, t_stack *b, int *rb, int *direction);

void	progressive_presort(t_stack *a, t_stack *b, int chunk)
{
	int	range[2];
	int	direction;
	int	rb;

	presort_init(range, a->size, &direction, &rb);
	direction = presort_direction(a, range[0] + chunk);
	while (a->size > 3)
	{
		if (a->head->index < range[0])
		{
			presort_push_top(a, b, &rb, range);
			direction = 0;
		}
		else if (a->head->index < range[0] + chunk && a->head->index < range[1])
		{
			presort_push_bot(a, b, &rb, range);
			direction = 0;
		}
		else
		{
			if (direction == 0)
				direction = presort_direction(a, range[0] + chunk);
			presort_rotate(a, b, &rb, &direction);
		}
	}
}

static void	presort_push_top(t_stack *a, t_stack *b, int *rb, int *range)
{
	while (*rb)
	{
		rotate(NULL, b);
		(*rb)--;
	}
	push(a, b);
	(*range)++;
}

static void	presort_push_bot(t_stack *a, t_stack *b, int *rb, int *range)
{
	push(a, b);
	(*rb)++;
	(*range)++;
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

static void	presort_rotate(t_stack *a, t_stack *b, int *rb, int *direction)
{
	if (*rb && direction >= 0)
	{
		rotation_control(a, b, 1);
		(*rb)--;
	}
	else
		rotation_control(a, NULL, *direction);
}
