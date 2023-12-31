#include <stdio.h>
#include "push_swap.h"
#include "ft_printf.h"

void	test_print_stack_inf(t_node *head)
{
	int		i;
	t_node	*curr = head;

	ft_dprintf(2, "\n<><><> PRINTING STACK <><><>\n");

	while (curr)
	{
		if (curr == head)
		{
			i = 0;
			ft_dprintf(2, "\n");
		}
		if (i != 0)
			ft_dprintf(2, " -> ");
		ft_dprintf(2, "%d", curr->value);
		curr = curr->next;
		i++;
	}
	ft_dprintf(2, "\n\n");
}

void	test_print_stack_infback(t_node *head)
{
	int		i;
	t_node	*curr = head;

	ft_dprintf(2, "\n<><><> PRINTING STACK <><><>\n");

	while (curr)
	{
		if (curr == head)
		{
			i = 0;
			ft_dprintf(2, "\n");
		}
		if (i != 0)
			ft_dprintf(2, " -> ");
		ft_dprintf(2, "%d(%d)", curr->value, curr->index);
		curr = curr->prev;
		i++;
	}
	ft_dprintf(2, "\n\n");
}

void	test_print_stack(t_node *head)
{
	int		i;
	t_node	*curr = head;

	i = 0;
	while (curr)
	{
		if (i != 0)
			ft_dprintf(2, " -> ");
		ft_dprintf(2, "%d(%d)", curr->value, curr->index);
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
		ft_dprintf(2, "\nSTACK_A: size=%-5d |", a->size);
		test_print_stack(a->head);
	}
	if (b)
	{
		ft_dprintf(2, "\nSTACK_B: size=%-5d |", b->size);
		test_print_stack(b->head);
	}
	ft_dprintf(2, "\n\n");
}
