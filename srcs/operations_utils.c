/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:02:44 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/04 05:22:14 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"


void	print_operation(t_opid i, t_stack *a)
{
	static const int	len[] = {3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4};
	static const char	*str[] = {
		"sa\n", "sb\n", "ss\n",
		"pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n",
		"rra\n", "rrb\n", "rrr\n"};

	if (write(STDOUT_FILENO, str[i], len[i]) == -1)
		free_and_exit(a, true);
}
