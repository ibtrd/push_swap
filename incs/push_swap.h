/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:57:35 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/28 16:57:35 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stacks
{
	struct s_node	*head_a;
	size_t			size_a;
	struct s_node	*head_b;
	size_t			size_b;
}	t_stacks;

void	print_both_stacks(t_stacks *stacks); //REMOVE
void	test_print_stack(t_node *head);	//REMOVE
void	test_print_stack_inf(t_node *head); //REMOVE
void	test_print_stack_infback(t_node *head); //REMOVE

int		check_argv(char **argv);
void	parse_argv(char **argv, t_stacks *stacks);
void	parse_one(char *str, t_stacks *stacks);
int		get_value(char *str, t_stacks *stacks);
int		is_duplicate_value(t_stacks *stacks, int value);
void	init_stacks(t_stacks *stacks);
void	add_to_stack(t_node **head, int value);
void	clear_stack(t_node *head);
void	free_and_exit(t_stacks *stacks, bool error);
int		is_stack_sorted(t_node *head);

#endif