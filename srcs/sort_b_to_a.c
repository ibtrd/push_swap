/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:58:36 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/01 01:43:26 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "ft_printf.h" //REMOVE

int		get_node_index(t_stack *stack, int top, int bot);
t_node	*get_node(t_stack *stack, int target);
int		single_node_distance(t_node *head, t_node *target);
t_node	*get_single_node(t_stack *stack, int target);

void	insert_sort_b_to_a(t_stack *a, t_stack *b)
{
	int		security = 0;
	
	bool	bot_stack;
	int		control;

	control = 0;
	bot_stack = false;
	while (b->size)
	{
		if (control = 0)
			control = set_control(a, b, bot_stack);
		else
		{
			instruction_check()
		}
		rotation_control(NULL, b, control, true);
		if (security++ > 5000)
			free_and_exit(a, b , false);
	}
}

int	set_control(t_stack *a, t_stack *b, bool bot_stack)
{
	t_node	*top;
	t_node	*bot;

	top = get_biggest_node(b);
	if (!bot_stack)
		bot = set_bottom_target(b, a->size + b->size, top, bot_stack);
	if (bot)
		return (single_node_distance(b->head, bot));
	if (bot_stack)
		return(get_closest_node(b->head, top->index, bot->index));
	return (single_node_distance(b, top));
}

t_node	*set_bottom_target(t_stack *b, int size, t_node *top, bool *status)
{
	if (top->index < size / 3 * 2)
	{
		*status = true;
		return (get_single_node(b, top->chunk_min));
	}
	return (NULL);
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
