/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:15:43 by glevin            #+#    #+#             */
/*   Updated: 2024/10/01 12:44:24 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

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
	t_node	*temp;

	temp = stack->node;
	stack->node = stack->node->next;
	return (temp);
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

void	pa(t_stack *stack1, t_stack *stack2)
{
	ft_printf("pa\n");
	push_stack(stack1, stack2);
}
void	pb(t_stack *stack2, t_stack *stack1)
{
	ft_printf("pb\n");
	push_stack(stack2, stack1);
}
