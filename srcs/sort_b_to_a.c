/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:58:36 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/01 00:13:05 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "ft_printf.h" //REMOVE

int		get_node_index(t_stack *stack, int top, int bot);
t_node	*get_node(t_stack *stack, int target);
int		single_node_distance(t_node *head, t_node *target);

void	korean_sort_b_to_a(t_stack *a, t_stack *b)
{
	t_node	*top;
	t_node	*target;
	int		direction;
	int		low;

	int security = 0;
	low = 0;
	direction = 0;
	while (b->size)
	{
		top = get_biggest_node(b);

		if (!low && a->size > (a->size + b->size) / 5 * 4)
		{
			target = get_node(b, top->chunk_min);
			if (target)
			{
				ft_dprintf(2, "lowtarget=%d\n", target->index);
				direction = get_node_index(b, top->index, top->chunk_min);
				while (target && b->head->index != target->index)
				{
							ft_dprintf(2, "%d direction\n", direction);
					ft_dprintf(2, "%d value\n", b->head->value);
					ft_dprintf(2, "%d index\n", b->head->index);
					ft_dprintf(2, "%d top\n", top->index);
					ft_dprintf(2, "%d min\n", top->chunk_min);
					if (direction < 0)
						reverse_rotate(NULL, b, true);
					else
						rotate(NULL, b, true);
				}
				push(b, a, true);
				if (a->head->index < a->head->next->index - 1)
					rotate(a, NULL, true);
				low = 1;
			}
		}
		else
		{
			direction = single_node_distance(b->head, top);

			while (b->head->index != top->index)
			{
				if (direction < 0)
					reverse_rotate(NULL, b, true);
				else
					rotate(NULL, b, true);
			}
			push(b, a, true);
		}
		if (!low)
		{
			direction = get_node_index(b, top->index, a->head->prev->index + 1);
		}
		if (low && a->size && b->size && b->head->index == a->head->prev->index + 1)
		{
			push(b, a, true);
			reverse_rotate(a, NULL, true);
		}
		else if (b->head->index == top->index)
		{
			push(b, a, true);
		}
		else if (direction < 0)
			reverse_rotate(NULL, b, true);
		else
			rotate(NULL, b, true);
		// while (a->size && a->head->index == a->head->prev->index + 1 && a->head->index == a->head->next->index - 1 && a->head->index != a->head->prev->index)
		// {
		// 	reverse_rotate(a, NULL, true);
		// 	low = 0;
		// }
		if (security++ > 5000)
			free_and_exit(a, b , false);
	}
}


int	get_node_index(t_stack *stack, int top, int bot)
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


int	set_direction(t_stack *a, int min, int max)
{
	t_node	*curr;
	int		i;

	i = 0;
	curr = a->head;
	while (i < a->size && (curr->index < min || curr->index > max))
	{
		i++;
		curr = curr->next;
	}
	if (i < a->size / 2)
		return (1);
	return (-1);
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

int	single_node_distance(t_node *head, t_node *target)
{
	t_node	*rot;
	t_node	*rev;
	int		i;

	i = 0;
	rot = head;
	rev = head;
	while (1)
	{
		if (rev == target)
			return (-i);
		if (rot == target)
			return (i);
		rot = rot->next;
		rev = rev->prev;
		i++;
	}
}
