/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plouc_sortv2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 01:40:11 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/30 00:57:40 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_closest_index(t_node *head, int value);

void	sort_n_elements(t_stack *a, t_stack *b, int div)
{
	int	chunck_size;
	int	first;
	int	i;
	int	last;
	int j;

	chunck_size = a->size / div;
	first = 1;
	last = div;
	while (1)
	{
		push_chuncks(a, n)
	}

}

int	push_chuncks(t_stack a, int start, int end)
{
	
}

int	get_closest_index(t_node *head, int value)
{
	t_node	*rot;
	t_node	*rev;
	int		i;

	i = 0;
	rot = head;
	rev = head;
	while (1)
	{
		if (rev->value == value)
			return (-i);
		if (rot->value == value)
			return (i);
		rot = rot->next;
		rev = rev->prev;
		i++;
	}
}
