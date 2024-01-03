/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:02:44 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/03 17:27:45 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "libft.h"

void	print_operation(enum e_operation i)
{
	static const int	len[] = {3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4};
	static const char	*str[] = {
		"sa\n", "sb\n", "ss\n",
		"pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n",
		"rra\n", "rrb\n", "rrr\n"};

	write(STDOUT_FILENO, str[i], len[i]);
}

void	print_operation_list(t_op **list)
{
	t_op	*curr;

	curr = *list;
	while (curr)
	{
		print_operation(curr->op);
		curr = curr->next;
	}
}
