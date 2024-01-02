/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:58:36 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/02 03:47:38 by ibertran         ###   ########lyon.fr   */
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
	
	// int		security = 0;

	bot_stack = 0;
	direction = 0;
	while (b->head)
	{
		if (direction == 0)
			direction = set_direction(a, b);
		instruction(a, b, &direction, &bot_stack);
		// if (security++ > 9000)
		// 	free_and_exit(a, b, true);
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
	else if (!*bot_stack && b->head->value >= a->head->chunk_min)
	{
		// ft_dprintf(2, "pushing to bot stack: index=%d\n", b->head->index);
		push(b, a, true);
		rotate(a, NULL, true);
		*bot_stack += 1;
		// ft_dprintf(2, "\tbot_stack value =%d\n", *bot_stack);
		*direction = 0;
	}
	else if (b->head->index == a->head->prev->index + 1)
	{
		// ft_dprintf(2, "pushing to bot stack: index=%d\n", b->head->index);
		push(b, a, true);
		rotate(a, NULL, true);
		*bot_stack += 1;
		// ft_dprintf(2, "\tbot_stack value =%d\n", *bot_stack);
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
	// if (to_top < 0)
	// {
	// 	to_top += *bot_stack;
	// 	if (to_top >= 0)
	// 		return (-1);
	// }
		

	// if (to_top * ((to_top > 0) - (to_top < 0)))
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
	// ft_dprintf(2, "bot stack reset!\n\n");
	// ft_dprintf(2, "\tbot_stack value =%d\n", *bot_stack);
	while (a->head->index == a->head->prev->index + 1)
	{
		reverse_rotate(a, NULL, true);
		*bot_stack -= 1;
		// ft_dprintf(2, "\tbot_stack value =%d\n", *bot_stack);
	}
}
