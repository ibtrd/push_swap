/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:10:42 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/04 09:14:39 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	init_stacks(&a, &b);
	if (!check_argv(argv + 1))
		free_and_exit(&a, true);
	parse_argv(argv + 1, &a);
	if (!a.size)
		free_and_exit(&a, true);
	read_instructions(&a, &b);
}

void	free_and_exit(t_stack *stack, bool error)
{
	clear_stack(stack->head);
	clear_stack(stack->sister->head);
	if (error)
		write(STDERR_FILENO, "Error\n", 6);
	exit(error);
}

void	print_ok_ko(t_stack *stack, bool result)
{
	if (result)
		write(STDOUT_FILENO, "OK", 2);
	else
		write(STDOUT_FILENO, "KO", 2);
	free_and_exit(stack, false);
}
