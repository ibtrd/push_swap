/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:33:41 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/02 07:45:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#include <stdio.h> //REMOVE

void	set_ranges(double chunk[3][2], int start, int end);

void	median_presort(t_stack *a, t_stack *b, int start, int end)
{
	double	chunk[3][2];
	int i = 0;
	int rot_b = 0;
	
	set_ranges(chunk, start, end);
	while(end - start > 3 && i < end - start)
	{
		if (ft_isrange(a->head->index, chunk[1][0], chunk[1][1]))
		{	
			while (rot_b)
			{
				rotate(NULL, b, true);
				rot_b--;
			}
			a->head->chunk_min = chunk[1][0];
			push(a, b, true);
		}
		else if (ft_isrange(a->head->index, chunk[0][0], chunk[0][1]))
		{
			a->head->chunk_min = chunk[0][0];
			push(a, b, true);
			rot_b++;
		}
		else if (rot_b)
		{
			rotate(a, b, true);
			rot_b--;
		}
		else
			rotate(a, NULL, true);
		i++;		
	}
	while (rot_b)
	{
		rotate(NULL, b, true);
		rot_b--;
	}
	if (chunk[2][1] - chunk[2][0] > 3)
		median_presort(a, b, chunk[2][0], chunk[2][1]);
	else
		sort_three_elements(a);
}

void	set_ranges(double chunk[3][2], int start, int end)
{	
	double x;
	
	x = 100 / (double)PRESORT;
	chunk[0][0] = start;
	chunk[0][1] = start + (end - start) / x / 2;
	chunk[1][0] = start + (end - start) / x / 2 + 1;
	chunk[1][1] = start + (end - start) / x;
	chunk[2][0] = start + (end - start) / x + 1;
	chunk[2][1] = end;
}
