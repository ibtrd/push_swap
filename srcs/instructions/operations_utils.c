/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:02:44 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/02 17:54:02 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "libft.h"

void	operation_to_list(t_stack *stack, enum e_operation i)
{
	t_op	*new;

	new = op_new(i);
	if (!new)
		free_and_exit(stack, NULL, true);
	op_add_front(stack->operations, new);
}

void	print_operation(enum e_operation i)
{
	static const char	*str[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", \
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	#include "ft_printf.h"
	ft_dprintf(2, "voici le i qui bug=%d\n", i);
	if (i < 8)
		write(STDOUT_FILENO, str[i], 3);
	else
		write(STDOUT_FILENO, str[i], 4);
}
