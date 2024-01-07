/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:10:42 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/07 07:59:01 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "checker_bonus.h"

static void	print_result(t_stack *stack, bool result);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	bool	sorted;

	if (argc == 1)
		return (0);
	init_stacks(&a, &b);
	if (!check_argv(argv + 1))
		free_and_exit(&a, true);
	parse_argv(argv + 1, &a);
	if (!a.size)
		free_and_exit(&a, true);
	read_instructions(&a, &b);
	sorted = is_stack_sorted(a.head);
	print_result(&b, sorted);
}

static void	print_result(t_stack *stack, bool result)
{
	if (result && !stack->head)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	free_and_exit(stack, false);
}

void	free_and_exit(t_stack *stack, bool error)
{
	clear_stack(stack->head);
	clear_stack(stack->sister->head);
	if (error)
		write(STDERR_FILENO, "Error\n", 6);
	exit(error);
}
