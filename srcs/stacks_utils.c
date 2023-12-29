#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

void	add_to_stack(t_node **head, int value)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit(999);
	new->value = value;
	if (!*head)
	{
		new->next = new;
		new->prev = new;
		*head = new;
	}
	else
	{
		new->next = *head;
		new->prev = (*head)->prev;
		(*head)->prev->next = new;
		if ((*head)->next == *head)
			(*head)->next = new;
		(*head)->prev = new;
	}
}

void	init_stacks(t_stacks *stacks)
{
	stacks->head_a = NULL;
	stacks->size_a = 0;
	stacks->biggest_a = INT_MIN;
	stacks->head_b = NULL;
	stacks->size_b = 0;
}

void	clear_stack(t_node *head)
{
	t_node	*temp;

	if (!head)
		return ;
	head->prev->next = NULL;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
