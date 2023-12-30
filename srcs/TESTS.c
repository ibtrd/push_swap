#include <stdio.h>
#include "push_swap.h"

void	test_print_stack_inf(t_node *head)
{
	int		i;
	t_node	*curr = head;

	printf("\n<><><> PRINTING STACK <><><>\n");

	while (curr)
	{
		if (curr == head)
		{
			i = 0;
			printf("\n");
		}
		if (i != 0)
			printf(" -> ");
		printf("%d", curr->value);
		curr = curr->next;
		i++;
	}
	printf("\n\n");
}

void	test_print_stack_infback(t_node *head)
{
	int		i;
	t_node	*curr = head;

	printf("\n<><><> PRINTING STACK <><><>\n");

	while (curr)
	{
		if (curr == head)
		{
			i = 0;
			printf("\n");
		}
		if (i != 0)
			printf(" -> ");
		printf("%d(%d)", curr->value, curr->index);
		curr = curr->prev;
		i++;
	}
	printf("\n\n");
}

void	test_print_stack(t_node *head)
{
	int		i;
	t_node	*curr = head;

	i = 0;
	while (curr)
	{
		if (i != 0)
			printf(" -> ");
		printf("%d(%d)", curr->value, curr->index);
		curr = curr->next;
		i++;
		if (curr == head)
			break ;
	}
}

void	print_both_stacks(t_stack *a, t_stack *b)
{
	if (a)
	{
		printf("\nSTACK_A: size=%-5d |", a->size);
		test_print_stack(a->head);
	}
	if (b)
	{
		printf("\nSTACK_B: size=%-5d |", b->size);
		test_print_stack(b->head);
	}
	printf("\n\n");
}
