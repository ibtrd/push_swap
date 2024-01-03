/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   korean_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:58:36 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/02 22:04:06 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_node_index(t_node *head, int index);
int	get_node_index_range(t_node *head, int min, int max);
int	set_directionkr(t_stack *a, int min, int max);
int	btoa_set_direction(t_stack *b, int target);

void	korean_sort(t_stack *a, t_stack *b, int chunk)
{
	int	i;
	int	rb_carry;
	int direction = 0;
	int max = a->size - 3;

	i = 0;
	rb_carry = 0;
	while (a->size != 3)
	{
		if (a->head->index >= max)
			rotate(a, NULL);
		else if (a->head->index <= i)
		{
			while (rb_carry)
			{
				rotate(NULL, b);
				rb_carry--;
			}
			push(a, b);
			i++;
			direction = 0;
		}
		else if (a->head->index > i && a->head->index < i + chunk)
		{
			push(a, b);
			rb_carry++;
			i++;
			direction = 0;
		}
		else
		{
			if (direction == 0)
				direction = set_directionkr(a, 0, i + chunk);
			if (direction < 0)
				reverse_rotate(a, NULL);
			else if (rb_carry)
			{
				rotate(a, b);
				rb_carry--;
			}
			else
				rotate(a, NULL);
		}
	}
}

int	get_node_index(t_node *head, int index)
{
	t_node	*rot;
	t_node	*rev;
	int		i;

	i = 0;
	rot = head;
	rev = head;
	while (1)
	{
		if (rot->index == index)
			return (i);
		if (rev->index == index)
			return (-i);
		rot = rot->next;
		rev = rev->prev;
		i++;
	}
}

int	get_node_index_range(t_node *head, int min, int max)
{
	t_node	*rot;
	t_node	*rev;
	int		i;

	if (!head)
		return (0);
	i = 0;
	rot = head;
	rev = head;
	while (1)
	{
		if (rot->index >= min && rot->index <= max)
		{
			if (rev->index >= min && rev->index <= max
				&& rev->index < rot->index)
				return (-i);
			return (i);
		}
		if (rev->index >= min && rev->index <= max)
			return (-i);
		rot = rot->next;
		rev = rev->prev;
		i++;
	}
}

int	set_directionkr(t_stack *a, int min, int max)
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

int	get_len_to_node(t_node *head, t_node *target)
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
