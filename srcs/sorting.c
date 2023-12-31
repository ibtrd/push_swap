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

// void	sort_up_to_five(t_stack *a, t_stack *b)
// {
// 	while (a->size != 3)
// 		pb(a, b);
// 	sort_three_elements(a);
// 	while (b->size != 0)
// 	{
// 		while (b->head->value > a->head->next->value && )
// 			ra(a);
// 		pa(a, b);
// 		if (a->head->value > a->head->prev->value)
// 			ra(a);
// 		else if (a->head->value > a->head->next->value)
// 			sa(a);
// 	}
// }
