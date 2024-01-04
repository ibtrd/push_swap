/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:42:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/04 09:40:53 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

#include <stddef.h>
#include <stdbool.h>

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
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	char			id;
	struct s_node	*head;
	int				size;
	struct s_stack	*sister;
}	t_stack;

typedef void	(*t_opfunction)(t_stack, t_stack);

# define SIGN "+-"
# define SEP "\t\n\v\f\r "
# define SEP_AND_SIGN "\t\n\v\f\r +-"

void	swap(t_stack *a, t_stack *b);
void	rotate(t_stack *a, t_stack *b);
void	push(t_stack *from, t_stack *to);
void	reverse_rotate(t_stack *a, t_stack *b);
void	init_stacks(t_stack *a, t_stack *b);
int		check_argv(char **argv);
void	parse_argv(char **argv, t_stack *a);
void	free_and_exit(t_stack *stack, bool error);
void	add_to_stack(t_stack *a, int value);
void	clear_stack(t_node *head);
int		is_stack_sorted(t_node *head, size_t size);
void	read_instructions(t_stack *a, t_stack *b);

#endif
