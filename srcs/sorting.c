#include "push_swap.h"
#include <limits.h>

void	sort_two_elements(t_stack *a)
{
	if (a->head->value > a->head->next->value)
		swap(a, NULL, true);
}

void	sort_three_elements(t_stack *a)
{
	t_node	*biggest;

	biggest = get_biggest_node(a);
	if (a->head->index == biggest->index)
		rotate(a, NULL, true);
	else if (a->head->next->index == biggest->index)
		reverse_rotate(a, NULL, true);
	if (a->head->index > a->head->next->index)
		swap(a, NULL, true);
}

void	sort_up_to_five(t_stack *a, t_stack *b)
{
	while (b->size <= 1)
	{
		if (a->head->index == 0 || a->head->index == 1)
			push_to_b(a, b, true);
		else
			rotate(a, b, true);
	}
	sort_three_elements(a);
	push_to_a(a, b, true);
	push_to_a(a, b, true);
	if (a->head->index > a->head->next->index)
		swap(a, NULL, true);
}
