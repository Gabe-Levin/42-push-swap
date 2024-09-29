/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:50:33 by glevin            #+#    #+#             */
/*   Updated: 2024/09/28 15:55:47 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// TODO: delete me
void	print_ll(t_node *head)
{
	while (head)
	{
		ft_printf("%d\n", head->data);
		head = head->next;
	}
}
t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->node = NULL;
	stack->size = 0;
	return (stack);
}

t_stack	*add_node(t_stack *stack, int data)
{
	t_node	*new_node;
	t_node	*last;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		NULL;
	new_node->data = data;
	new_node->above_median = true;
	new_node->cheapest = false;
	new_node->index = 0;
	new_node->push_cost = 0;
	new_node->target = NULL;
	new_node->next = NULL;
	last = stack->node;
	if (last == NULL)
	{
		stack->node = new_node;
		return (stack);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*next;
	t_node	*current;

	current = stack->node;
	next = current->next;
	while (next)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

t_stack	*push_to_stack(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		NULL;
	new_node->data = data;
	new_node->next = stack->node;
	stack->node = new_node;
	return (stack);
}

t_node	*pop_stack(t_stack *stack)
{
	t_node *temp;

	temp = stack->node;
	stack->node = stack->node->next;
	return (temp);
}