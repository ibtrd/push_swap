/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:09:40 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/04 03:12:18 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	presort_init(int *range, int stack_size, int *direction, int *rb)
{
	range[0] = 0;
	range[1] = stack_size - 3;
	*direction = 0;
	*rb = 0;
}
