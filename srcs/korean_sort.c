/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   korean_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:58:36 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/30 10:02:24 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_node_index(t_node *head, int index);
int	get_node_index_range(t_node *head, int min, int max);
int	get_rotation_direction(t_stack *stack);

void	korean_sort(t_stack *a, t_stack *b, int chunck)
{
	int	i;
	int	rotate;
	int target;
	i = 0;
	rotate = 0;
	while (a->size)
	{
		if (a->head->index <= i)
		{
			while (rotate)
			{
				rb(b);
				rotate--;
			}
			pb(a, b);
			i++;
		}
		else if (a->head->index > i && a->head->index < i + chunck)
		{
			pb(a, b);
			i++;
			rotate++;
		}
		else
		{
			target = get_node_index_range(a->head, 0, i);
			if (target < 0 && -target < a->size / 20)
				rra(a);
			else if (rotate)
			{
				rr(a, b);
				rotate--;
			}
			else
				ra(a);
		}
	}
	korean_sort_back(a, b);
}

void	korean_sort_back(t_stack *a, t_stack *b)
{
	t_node	*biggest;
	int	target;
	int swap;

	swap = 0;
	while (b->size)
	{
		biggest = get_biggest_node(b);
		target = get_len_to_node(b->head, biggest);
		if (target > 0)
		{
			while (b->head->index < biggest->index - 1)
				rb(b);
		}
		else if (target < 0)
		{
			while (b->head->index < biggest->index - 1)
				rrb(b);
		}
		pa(a, b);
		if (a->head->index > a->head->next->index)
			sa(a);
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
		if (rev->index == index)
			return (-i);
		if (rot->index == index)
			return (i);
		rot = rot->next;
		rev = rev->prev;
		i++;
	}
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


int	get_node_index_range(t_node *head, int min, int max)
{
	t_node	*rot;
	t_node	*rev;
	int		i;

	i = 0;
	rot = head;
	rev = head;
	while (1)
	{
		if (rev->index >= min && rev->index <= max)
			return (-i);
		if (rev->index >= min && rev->index <= max)
			return (i);
		rot = rot->next;
		rev = rev->prev;
		i++;
	}
}
