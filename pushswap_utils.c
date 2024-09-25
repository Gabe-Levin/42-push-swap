/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:13:01 by glevin            #+#    #+#             */
/*   Updated: 2024/09/25 12:31:03 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->node == NULL)
		return ;
	first = stack->node;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->node = second;
}

void	ss(t_stack *stack1, t_stack *stack2)
{
	swap_stack(stack1);
	swap_stack(stack2);
}

void	push_stack(t_stack *stack1, t_stack *stack2)
{
	t_node	*temp;

	temp = pop_stack(stack2);
	if (stack1->size == 0)
	{
		temp->next = NULL;
		stack1->node = temp;
	}
	else
		push_to_stack(stack1, temp->data);
	stack2->size--;
	stack1->size++;
}

void	rotate_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*next;

	temp = stack->node;
	stack->node = stack->node->next;
	next = stack->node->next;
	while (next->next)
		next = next->next;
	next->next = temp;
	next->next->next = NULL;
}

void	rr(t_stack *stack1, t_stack *stack2)
{
	rotate_stack(stack1);
	rotate_stack(stack2);
}

void	rev_rotate_stack(t_stack *stack)
{
	t_node	*next;

	next = stack->node->next;
	while (next->next->next)
		next = next->next;
	push_to_stack(stack, next->next->data);
	next->next = NULL;
}

void	rrr(t_stack *stack1, t_stack *stack2)
{
	rev_rotate_stack(stack1);
	rev_rotate_stack(stack2);
}
