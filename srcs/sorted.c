#include "push_swap.h"

int	is_stack_sorted(t_node *head)
{
	t_node *curr;

	curr = head;
	while (curr->next != head)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	plouc_sort_atob(t_stacks *stacks);
void	plouc_sort_btoa(t_stacks *stacks);

void	sort_stack_a(t_stacks *stacks)
{
	if (stacks->size_a == 2)
		sort_two_elements(stacks);
	else if (stacks->size_a == 3)
		sort_three_elements(stacks);
	else
	{
		plouc_sort_atob(stacks);
		plouc_sort_btoa(stacks);
	}

}

void	sort_two_elements(t_stacks *stacks)
{
	if (stacks->head_a->value > stacks->head_a->next->value)
		sa(stacks);
}

void	sort_three_elements(t_stacks *stacks)
{
	if (stacks->head_a->value == stacks->biggest_a)
		ra(stacks);
	else if (stacks->head_a->next->value == stacks->biggest_a)
		rra(stacks);
	if (stacks->head_a->value > stacks->head_a->next->value)
		sa(stacks);
}
