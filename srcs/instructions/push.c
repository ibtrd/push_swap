#include <unistd.h>
#include "push_swap.h"

static void	instruction_push(t_node **from, t_node **to);

void	pa(t_stacks *stacks)
{
	instruction_push(&stacks->head_b, &stacks->head_a);
	stacks->size_a++;
	stacks->size_b--;
	if (!stacks->size_b)
		stacks->head_b = NULL;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks)
{
	instruction_push(&stacks->head_a, &stacks->head_b);
	stacks->size_a--;
	if (!stacks->size_a)
		stacks->head_a = NULL;
	stacks->size_b++;
	write(1, "pb\n", 3);
}

static void	instruction_push(t_node **from, t_node **to)
{
	t_node	*temp;

	if (!*from)
		return ;
	temp = *from;
	(*from)->prev->next = (*from)->next;
	(*from)->next->prev = (*from)->prev;
	*from = (*from)->next;
	if (!*to)
	{
		temp->prev = temp;
		temp->next = temp;
	}
	else
	{
		temp->prev = (*to)->prev;
		temp->next = *to;
		(*to)->prev->next = temp;
		(*to)->prev = temp;
	}
	*to = temp;
}
