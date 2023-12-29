/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:57:04 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/29 01:31:01 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	init_stacks(&stacks);
	if (!check_argv(argv + 1))
		free_and_exit(&stacks, 1);
	parse_argv(argv + 1, &stacks);
	if (is_stack_sorted(stacks.head_a))
		free_and_exit(&stacks, 0);
	//print_both_stacks(&stacks); //REMOVE
	sort_stack_a(&stacks);
	//print_both_stacks(&stacks); //REMOVE
	free_and_exit(&stacks, 0);
}

int	check_argv(char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_ischarset(argv[i][j], "+- 0123456789"))
				return (0);
			if (ft_ischarset(argv[i][j], "+-") && !ft_ischarset(argv[i][j + 1], "0123456789"))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_and_exit(t_stacks *stacks, bool error)
{
	clear_stack(stacks->head_a);
	clear_stack(stacks->head_b);
	if (error)
		write(2, "Error\n", 6);
	exit(error);
}
