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

# define PRESORT 33

# ifndef FORCEPRINT
#  define FORCEPRINT 0
# endif

# ifndef PRESORT_MODE
#  define PRESORT_MODE 0
# endif

enum e_operation
{
	SWAP_A,
	SWAP_B,
	SWAP_AB,
	PUSH_A,
	PUSH_B,
	ROTATE_A,
	ROTATE_B,
	ROTATE_AB,
	REVERSE_ROTATE_A,
	REVERSE_ROTATE_B,
	REVERSE_ROTATE_AB,
};

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
	struct s_op		**operations;
	struct s_node	**sister;
}	t_stack;

typedef struct s_op
{
	enum e_operation	op;
	struct s_op			*next;
}	t_op;

typedef struct s_rotations
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_rotations;

void	swap(t_stack *a, t_stack *b);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *a, t_stack *b);

//PARSING
int		check_argv(char **argv);
void	parse_argv(char **argv, t_stack *a);

//SORTING

int		is_stack_sorted(t_node *head, size_t size);
void	sort_two_elements(t_stack *stack);
void	sort_three_elements(t_stack *stack);
void	sort_up_to_five(t_stack *a, t_stack *b);
void	sort_n_elements(t_stack *a, t_stack *b, int div);

void	korean_sort_back(t_stack *a, t_stack *b, int chunck);

//STACKS
void	init_stacks(t_stack *a, t_stack *b, t_op **list);
void	set_index(t_stack *stack);
void	add_to_stack(t_node **head, int value);
void	set_biggest_and_smallest(t_stack *stack);
void	clear_stack(t_node *head);
int		get_len_to_node(t_node *head, t_node *target);
t_node	*get_biggest_node(t_stack *stack);
void	rotation_control(t_stack *a, t_stack *b, int control);

//UTILS
void	free_and_exit(t_stack *a, t_stack *b, bool error);

//REMOVE
void	print_both_stacks(t_stack *a, t_stack *b);

//MEDIAN SORTING
void	median_presort(t_stack *a, t_stack *b, int start, int end);




//PRESORT
void	progressive_presort(t_stack *a, t_stack *b, int chunck);
int		chunk_size_formula(int size);

//OPERATION LISTS
void	operation_to_list(t_stack *stack, enum e_operation i);
void	print_operation(enum e_operation i);
void	print_operation_list(t_op **list);
void	op_clear(t_op **list);

//SIMPLIFIER
void	simplify_operations(t_op **list);
void	init_counter(t_rotations *counter);
int		is_rotation(enum e_operation i);

#endif