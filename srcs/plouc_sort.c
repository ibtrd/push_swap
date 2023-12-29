#include "push_swap.h"
#include <stdio.h>

int		get_node_index(t_node *head, int value);
int		get_lowest_index(int rot, int rev);
void	plouc_sort_reverse(t_stacks *stacks);
int	get_node_index_range(t_node *head, int value);

void	plouc_sort_atob(t_stacks *stacks)
{
	t_node	*curr;
	int		smallest;
	int		small_index;
	int		biggest;
	int		big_index;
	int		needtorb = 0;

	while (stacks->size_a)
	{
		smallest = 2147483647;
		biggest = -2147483648;
		curr = stacks->head_a;
		while (curr)
		{
			if (curr->value < smallest)
				smallest = curr->value;
			if (curr->value > biggest)
				biggest = curr->value;
			curr = curr->next;
			if (curr == stacks->head_a)
				break ;
		}
		small_index = get_node_index(stacks->head_a, smallest);
		big_index = get_node_index_range(stacks->head_a, biggest);
		int index;
		index = get_lowest_index(small_index, big_index);

		if (stacks->head_a->value == smallest || stacks->head_a->value == biggest)
		{
			while (needtorb)
			{
				rb(stacks);
				needtorb--;
			}
		}
		if (index > 0 - needtorb)
		{
			while (stacks->head_a->value > smallest * 2 && stacks->head_a->value < biggest * 0.9)
			{
				if (needtorb)
				{
					rr(stacks);
					needtorb--;
				}
				else
					ra(stacks);
			}
		}
		else
		{
			while (stacks->head_a->value > smallest * 2 && stacks->head_a->value < biggest * 0.9)
				rra(stacks);		
		}
		while (needtorb)
		{
			rb(stacks);
			needtorb--;
		}
		if (stacks->head_a->value < biggest * 0.9)
			pb(stacks);
		else
		{
			pb(stacks);
			if (stacks->size_b > 1)
				needtorb++;
		}
	}
}

void	plouc_sort_btoa(t_stacks *stacks)
{
	t_node	*curr;
	int		biggest;
	int	big_index;

	while (stacks->size_b)
	{
		biggest = -2147483648;
		curr = stacks->head_b;
		while (curr)
		{
			if (curr->value > biggest)
				biggest = curr->value;
			curr = curr->next;
			if (curr == stacks->head_b)
				break ;
		}
		big_index = get_node_index(stacks->head_b, biggest);

		if (big_index >= 0)
		{
			while (stacks->head_b->value != biggest)
				rb(stacks);
		}
		else
		{
			while (stacks->head_b->value != biggest)
				rrb(stacks);		
		}
		pa(stacks);
		}
	}

int	get_node_index(t_node *head, int value)
{
	t_node	*rot;
	t_node	*rev;
	int		i;

	i = 0;
	rot = head;
	rev = head;
	while (1)
	{
		if (rev->value == value)
			return (-i);
		if (rot->value == value)
			return (i);
		rot = rot->next;
		rev = rev->prev;
		i++;
	}
}

int	get_node_index_range(t_node *head, int value)
{
	t_node	*rot;
	t_node	*rev;
	int		i;

	i = 0;
	rot = head;
	rev = head;
	while (1)
	{
		if (rev->value <= value && rev->value >= value * 0.9)
			return (-i);
		if (rot->value <= value && rot->value >= value * 0.9)
			return (i);
		rot = rot->next;
		rev = rev->prev;
		i++;
	}
}

#include <stdio.h>

int	get_lowest_index(int i, int j)
{
	int abs_i;
	int abs_j;

	abs_i = i * ((i > 0) - (i < 0));
	abs_j = j * ((j > 0) - (j < 0));
	if (abs_i <= abs_j)
		return (i);
	return (j);
}
