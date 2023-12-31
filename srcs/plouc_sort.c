#include "push_swap.h"
#include <stdio.h>

int		get_node_index(t_node *head, int value);
int		get_lowest_index(int rot, int rev);
void	plouc_sort_reverse(t_stack *stacks);
int		get_node_index_range(t_node *head, int value);

void	plouc_sort_atob(t_stack *a, t_stack *b)
{
	t_node	*curr;
	int		smallest;
	int		small_index;
	int		biggest;
	int		big_index;
	int		needtorb = 0;

	while (a->size)
	{
		smallest = 2147483647;
		biggest = -2147483648;
		curr = a->head;
		while (curr)
		{
			if (curr->value < smallest)
				smallest = curr->value;
			if (curr->value > biggest)
				biggest = curr->value;
			curr = curr->next;
			if (curr == a->head)
				break ;
		}
		small_index = get_node_index(a->head, smallest);
		big_index = get_node_index(a->head, biggest);
		int index;
		index = get_lowest_index(small_index, big_index);

		if (a->head->value == smallest || a->head->value == biggest)
		{
			while (needtorb)
			{
				rb(b);
				needtorb--;
			}
		}
		if (index > 0 - needtorb)
		{
			while (a->head->value != smallest && a->head->value != biggest)
			{
				if (needtorb)
				{
					rr(a, b);
					needtorb--;
				}
				else
					ra(a);
			}
		}
		else
		{
			while (a->head->value != smallest && a->head->value != biggest)
				rra(a);		
		}
		while (needtorb)
		{
			rb(b);
			needtorb--;
		}
		if (a->head->value == biggest)
			pb(a, b);
		else
		{
			pb(a, b);
			if (b->size > 1)
				needtorb++;
		}
	}
}

void	plouc_sort_btoa(t_stack *a, t_stack *b)
{
	t_node	*curr;
	int		biggest;
	int	big_index;

	while (b->size)
	{
		biggest = -2147483648;
		curr = b->head;
		while (curr)
		{
			if (curr->value > biggest)
				biggest = curr->value;
			curr = curr->next;
			if (curr == b->head)
				break ;
		}
		big_index = get_node_index(b->head, biggest);

		if (big_index >= 0)
		{
			while (b->head->value != biggest)
				rb(b);
		}
		else
		{
			while (b->head->value != biggest)
				rrb(b);		
		}
		pa(a, b);
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


