/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   korean_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:58:36 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/31 21:26:11 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_node_index(t_node *head, int index);
int	get_node_index_range(t_node *head, int min, int max);
int	set_direction(t_stack *a, int min, int max);
int	btoa_set_direction(t_stack *b, int target);

// void	korean_sort(t_stack *a, t_stack *b, int chunck)
// {
// 	int	i;
// 	int	rb_carry;
// 	int direction = 0;

// 	i = 0;
// 	rb_carry = 0;
// 	while (a->size)
// 	{
// 		if (a->head->index <= i)
// 		{
// 			while (rb_carry)
// 			{
// 				rotate(NULL, b, true);
// 				rb_carry--;
// 			}
// 			push(a, b, true);
// 			i++;
// 			direction = 0;
// 		}
// 		else if (a->head->index > i && a->head->index < i + chunck)
// 		{
// 			push(a, b, true);
// 			rb_carry++;
// 			i++;
// 			direction = 0;
// 		}
// 		else
// 		{
// 			if (direction == 0)
// 				direction = set_direction(a, 0, i + chunck);
// 			if (direction < 0)
// 				reverse_rotate(a, NULL, true);
// 			else if (rb_carry)
// 			{
// 				rotate(a, b, true);
// 				rb_carry--;
// 			}
// 			else
// 				rotate(a, NULL, true);
// 		}
// 	}
// }

void	set_targets(t_stack *stack, t_node *biggest, t_node *smallest);

void	korean_sort_back(t_stack *a, t_stack *b, int chunck)
{
	t_node	*top;
	int		direction;
	int		low;

	(void)chunck;
	low = 0;
	direction = 0;
	while (b->size)
	{
		top = get_biggest_node(b);
		#include "ft_printf.h"
		//ft_dprintf(2, "biggest=%d\n", biggest->index);
		direction = btoa_set_direction(b, top->index);
		if (direction < 0)
		{
			while (b->head->index != top->index)
			{
				if (a->size && !low && b->head->index <= top->index)
				{
					push(b, a, true);
					rotate(a, NULL, true);
					low = 1;
				}
				else if (low && b->head->index == a->head->prev->index + 1)
				{
					push(b, a, true);
					rotate(a, NULL, true);
				}
				else if (a->size > 1 && a->head->index == a->head->prev->index + 1)
					reverse_rotate(a, b, true);
				else
					reverse_rotate(NULL, b, true);
			}
		}
		else
		{
			while (b->head->index != top->index)
			{
				if (a->size && !low && b->head->index <= top->index)
				{
					push(b, a, true);
					rotate(a, NULL, true);
					low = 1;
				}
				else if (low && b->head->index == a->head->prev->index + 1)
				{
					push(b, a, true);
					rotate(a, NULL, true);
				}
				else
					rotate(NULL, b, true);
			}
		}
		while (a->size && a->head->index == a->head->prev->index + 1 && a->head->index == a->head->next->index - 1 && a->head->index != a->head->prev->index)
		{
			reverse_rotate(a, NULL, true);
			low = 0;
		}
		if (b->head->index == top->index)
		{
			//ft_dprintf(2, "\tpushing=%d", b->head->index);
			push(b, a, true);
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
