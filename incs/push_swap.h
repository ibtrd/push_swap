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
#  define FORCEPRINT 1
# endif

typedef enum e_opid
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
	REVERSE_ROTATE_AB
}	t_opid;

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
	struct s_stack	*sister;
}	t_stack;

typedef struct s_op
{
	enum e_opid	op;
	struct s_op	*next;
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

int		check_argv(char **argv);
int		is_rotation(t_opid i);
int		is_stack_sorted(t_node *head, size_t size);
int		single_node_distance(t_node *head, t_node *target);
t_node	*get_biggest_node(t_stack *stack);
t_node	*get_single_node(t_stack *stack, int target);
void	add_to_stack(t_node **head, int value);
void	clear_stack(t_node *head);
void	free_and_exit(t_stack *stack, bool error);
void	init_counter(t_rotations *counter);
void	init_stacks(t_stack *a, t_stack *b, t_op **list);
void	insert_biggest_sort(t_stack *a, t_stack *b);
void	op_clear(t_op **list);
void	operation_to_list(t_stack *stack, t_opid i);
void	parse_argv(char **argv, t_stack *a);
void	presort_init(int *range, int stack_size, int *direction, int *rb);
void	print_operation(t_opid i, t_stack *a);
void	progressive_presort(t_stack *a, t_stack *b, int chunck);
void	push(t_stack *from, t_stack *to);
void	reverse_rotate(t_stack *a, t_stack *b);
void	rotate(t_stack *a, t_stack *b);
void	rotation_control(t_stack *a, t_stack *b, int direction);
void	set_index(t_stack *stack);
void	simplify_operations(t_stack *a);
void	sort_three_elements(t_stack *a);
void	sort_two_elements(t_stack *a);
void	swap(t_stack *a, t_stack *b);

#endif