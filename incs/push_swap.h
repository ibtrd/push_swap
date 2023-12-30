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

# define DIV 10

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	int				size;
	int				biggest;
	int				smallest;
}	t_stack;

// INSTRUCTIONS
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//PARSING
int		check_argv(char **argv);
void	parse_argv(char **argv, t_stack *a);

//SORTING

void	sort_two_elements(t_stack *stack);
void	sort_three_elements(t_stack *stack);
void	sort_up_to_five(t_stack *a, t_stack *b);
void	sort_n_elements(t_stack *a, t_stack *b, int div);

void	korean_sort(t_stack *a, t_stack *b, int chunck);
void	korean_sort_back(t_stack *a, t_stack *b);


//STACKS
void	init_stack(t_stack *stack);
void	set_index(t_stack *stack);
void	add_to_stack(t_node **head, int value);
void	free_and_exit(t_stack *a, t_stack *b, bool error);
void	set_biggest_and_smallest(t_stack *stack);
void	clear_stack(t_node *head);
int		is_stack_sorted(t_node *head);
int		get_len_to_node(t_node *head, t_node *target);
t_node	*get_biggest_node(t_stack *stack);

//REMOVE
void	print_both_stacks(t_stack *a, t_stack *b);

#endif