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

# define SIGN "+-"
# define SEP "\t\n\v\f\r "
# define SEP_AND_SIGN "\t\n\v\f\r +-"

typedef struct s_node
{
	int				value;
	int				index;
	int				chunk_min;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	char			id;
	struct s_node	*head;
	int				size;
}	t_stack;

// INSTRUCTIONS

void	swap(t_stack *a, t_stack *b, bool print);
void	push(t_stack *from, t_stack *to, bool print);
void	rotate(t_stack *a, t_stack *b, bool print);
void	reverse_rotate(t_stack *a, t_stack *b, bool print);


//PARSING
int		check_argv(char **argv);
void	parse_argv(char **argv, t_stack *a);

//SORTING

void	sort_two_elements(t_stack *stack);
void	sort_three_elements(t_stack *stack);
void	sort_up_to_five(t_stack *a, t_stack *b);
void	sort_n_elements(t_stack *a, t_stack *b, int div);

void	korean_sort(t_stack *a, t_stack *b, int chunck);
void	korean_sort_back(t_stack *a, t_stack *b, int chunck);

//STACKS
void	init_stacks(t_stack *a, t_stack *b);
void	set_index(t_stack *stack);
void	add_to_stack(t_node **head, int value);
void	set_biggest_and_smallest(t_stack *stack);
void	clear_stack(t_node *head);
int		is_stack_sorted(t_node *head);
int		get_len_to_node(t_node *head, t_node *target);
t_node	*get_biggest_node(t_stack *stack);
void	rotation_control(t_stack *a, t_stack *b, int control, bool print);

//UTILS
void	free_and_exit(t_stack *a, t_stack *b, bool error);


//REMOVE
void	print_both_stacks(t_stack *a, t_stack *b);

//MEDIAN SORTING
void	median_presort(t_stack *a, t_stack *b, int start, int end);

#endif