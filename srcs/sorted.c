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

void	sort_stack_a(t_stacks *stacks)
{
	if (stacks->size_a < 2)
		return ;
}
