/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_biggest_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:58:36 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/07 08:43:18 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	instruction(t_stack *a, t_stack *b, int *direction, int *bot_stack);
static int	set_direction(t_stack *a, t_stack *b);
static int	get_closest_node(t_stack *stack, int top, int bot);
static void	bring_bottom_stack_up(t_stack *a, int *bot_stack);

void	insert_biggest_sort(t_stack *a, t_stack *b)
{
	int		bot_stack;
	int		direction;

	bot_stack = 0;
	while (b->size)
	{
		direction = set_direction(a, b);
		instruction(a, b, &direction, &bot_stack);
	}
	bring_bottom_stack_up(a, &bot_stack);
}

static void	instruction(t_stack *a, t_stack *b, int *direction, int *bot_stack)
{
	if (a->head->index == a->head->prev->index + 1)
		bring_bottom_stack_up(a, bot_stack);
	else if (b->head->index == a->head->index - 1)
		push(b, a);
	else if (!*bot_stack)
	{
		push(b, a);
		rotate(a, NULL);
		*bot_stack += 1;
	}
	else if (b->head->index > a->head->prev->index)
	{
		push(b, a);
		rotate(a, NULL);
		*bot_stack += 1;
	}
	else
		rotation_control(NULL, b, *direction);
}

static int	set_direction(t_stack *a, t_stack *b)
{
	t_node	*top;
	t_node	*bot;
	int		to_top;
	int		to_bot;

	top = get_biggest_node(b);
	to_top = single_node_distance(b->head, top, b->size);
	bot = get_single_node(b, a->head->prev->index + 1);
	if (!bot)
		return (to_top);
	to_bot = single_node_distance(b->head, bot, b->size);
	return (get_closest_node(b, top->index, bot->index));
}

static int	get_closest_node(t_stack *stack, int top, int bot)
{
	t_node	*rot;
	t_node	*rev;
	int		i;

	i = 0;
	rot = stack->head;
	rev = stack->head;
	while (i < stack->size)
	{
		if (rev->index == top || rev->index == bot)
			return (-i);
		if (rot->index == top || rot->index == bot)
			return (i);
		rot = rot->next;
		rev = rev->prev;
		i++;
	}
	return (0);
}

static void	bring_bottom_stack_up(t_stack *a, int *bot_stack)
{
	while (a->head->index == a->head->prev->index + 1)
	{
		reverse_rotate(a, NULL);
		*bot_stack -= 1;
	}
}
