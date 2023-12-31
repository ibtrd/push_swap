/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:33:41 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/31 23:53:32 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#include <stdio.h> //REMOVE

int	yadesrestes(t_stack *stack, int start, int end);

void	median_presort(t_stack *a, t_stack *b, int start, int end)
{
	int	chunk[3][2];
	int i = 0;
	int rot_b = 0;
	
	chunk[0][0] = start;
	chunk[0][1] = start + (end - start) / 4;
	chunk[1][0] = start + (end - start) / 4 + 1;
	chunk[1][1] = start + (end - start) / 2;
	chunk[2][0] = start + (end - start) / 2 + 1;
	chunk[2][1] = end;
	
	#include "ft_printf.h"
	ft_dprintf(2, "1:%d-%d\n2:%d-%d\n3:%d-%d\n\n", chunk[0][0], chunk[0][1], chunk[1][0], chunk[1][1], chunk[2][0], chunk[2][1]);
	
	while(yadesrestes(a, chunk[0][0], chunk[1][1]))
	{
		if (ft_isrange(a->head->index, chunk[1][0], chunk[1][1]))
		{	
			while (rot_b)
			{
				rotate(NULL, b, true);
				rot_b--;
			}
			a->head->chunk_min = chunk[1][0] + 1;
			push(a, b, true);
			i++;
		}
		else if (ft_isrange(a->head->index, chunk[0][0], chunk[0][1]))
		{
			a->head->chunk_min = chunk[0][0] + 1;
			push(a, b, true);
			rot_b++;
			i++;
		}
		else if (rot_b)
		{
			rotate(a, b, true);
			rot_b--;
		}
		else
			rotate(a, NULL, true);
			
	}
	if (end - start > 10)
	{
		median_presort(a, b, chunk[2][0], chunk[2][1]);
	}
	else
	{
		while (a->size)
		{
			a->head->chunk_min = start / 5 * 4;
			push(a, b, true);
		}
	}
}

int	yadesrestes(t_stack *stack, int start, int end)
{
	t_node	*rot;
	t_node	*rev;
	int i;
	
	rot = stack->head;
	rev = stack->head;
	i = 0;
	while (i++ < stack->size)
	{
		if (ft_isrange(rot->index, start, end))
			return (1);
		if (ft_isrange(rev->index, start, end))
			return (1);
		rot = rot->next;
		rev = rev->prev;
	}
	return (0);
}

int	ft_isrange(int i, int start, int end)
{
	if (i >= start && i <= end)
		return (1);
	return (0);
}
