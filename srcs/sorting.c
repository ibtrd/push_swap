#include "push_swap.h"
#include <limits.h>

void	sort_two_elements(t_stack *stack)
{
	if (stack->head->value > stack->head->next->value)
		sa(stack);
}

void	sort_three_elements(t_stack *stack)
{
	//set_biggest_and_smallest(stack);
	if (stack->head->value == stack->biggest)
		ra(stack);
	else if (stack->head->next->value == stack->biggest)
		rra(stack);
	if (stack->head->value > stack->head->next->value)
		sa(stack);
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
