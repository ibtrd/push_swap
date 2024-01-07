/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progressive_presort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:53:53 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/07 09:31:07 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	presort_push_top(t_stack *a, t_stack *b, int *min, int *direction);
static void	presort_push_bot(t_stack *a, t_stack *b, int *min, int *direction);
static int	presort_direction(t_stack *a, int range);
static void	sort_three_elements(t_stack *a);

void	progressive_presort(t_stack *a, t_stack *b, int chunk)
{
	int	range[2];
	int	direction;

	range[0] = 0;
	range[1] = a->size - 3;
	direction = 0;
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
	sort_three_elements(a);
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
	if (b->size > 1)
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

static void	sort_three_elements(t_stack *a)
{
	t_node	*biggest;

	biggest = get_biggest_node(a);
	if (a->head->index == biggest->index)
		rotate(a, NULL);
	else if (a->head->next->index == biggest->index)
		reverse_rotate(a, NULL);
	if (a->head->index > a->head->next->index)
		swap(a, NULL);
}