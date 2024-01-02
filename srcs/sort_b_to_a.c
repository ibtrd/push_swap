/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:58:36 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/02 17:22:48 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_node_index(t_stack *stack, int top, int bot);
t_node	*get_node(t_stack *stack, int target);
int		single_node_distance(t_node *head, t_node *target);
t_node	*get_single_node(t_stack *stack, int target);
void	instruction(t_stack *a, t_stack *b, int *direction, int *bot_stack);
t_node	*set_bottom_target(t_stack *b, int size, t_node *top, int *status);
int		get_closest_node(t_stack *stack, int top, int bot);
int		set_direction(t_stack *a, t_stack *b);
void	bring_bottom_stack_up(t_stack *a, int *bot_stack);

#include "ft_printf.h"

void	insert_sort_b_to_a(t_stack *a, t_stack *b)
{
	int		bot_stack;
	int		direction;
	t_node	*biggest;

	bot_stack = 0;
	direction = 0;
	while (b->head)
	{
		while (a->size < 3)
		{
			biggest = get_biggest_node(b);
			direction = single_node_distance(b->head, biggest);
			while (direction > 0 && b->head->index != biggest->index)
				rotate(NULL, b, true);
			while (direction < 0 && b->head->index != biggest->index)
				reverse_rotate(NULL, b, true);
			push(b, a, true);
			direction = set_direction(a, b);
		}
		if (direction == 0)
			direction = set_direction(a, b);
		instruction(a, b, &direction, &bot_stack);
	}
	bring_bottom_stack_up(a, &bot_stack);
}

void	instruction(t_stack *a, t_stack *b, int *direction, int *bot_stack)
{
	if (a->head->index == a->head->prev->index + 1)
		bring_bottom_stack_up(a, bot_stack);
	else if (b->head->index == a->head->index - 1)
	{
		push(b, a, true);
		*direction = 0;
	}
	else if (!*bot_stack)
	{
		push(b, a, true);
		rotate(a, NULL, true);
		*bot_stack += 1;
		*direction = 0;
	}
	else if (b->head->index == a->head->prev->index + 1)
	{
		push(b, a, true);
		rotate(a, NULL, true);
		*bot_stack += 1;
		*direction = 0;
	}
	else
		rotation_control(NULL, b, *direction, true);
}

int	set_direction(t_stack *a, t_stack *b)
{
	t_node	*top;
	t_node	*bot;
	int		to_top;
	int		to_bot;

	top = get_biggest_node(b);
	to_top = single_node_distance(b->head, top);
	bot = get_single_node(b, a->head->prev->index + 1);
	if (!bot)
		return (to_top);
	to_bot = single_node_distance(b->head, bot);
	return (get_closest_node(b, top->index, bot->index));
}

int	get_closest_node(t_stack *stack, int top, int bot)
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

int	btoa_set_direction(t_stack *b, int target)
{
	t_node	*curr;
	int		i;

	i = 0;
	curr = b->head;
	while (i < b->size && curr->index != target)
	{
		i++;
		curr = curr->next;
	}
	if (i < b->size / 2)
		return (1);
	return (-1);
}

void	bring_bottom_stack_up(t_stack *a, int *bot_stack)
{
	while (a->head->index == a->head->prev->index + 1)
	{
		reverse_rotate(a, NULL, true);
		*bot_stack -= 1;
	}
}
