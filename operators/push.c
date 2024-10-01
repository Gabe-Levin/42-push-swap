/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:15:43 by glevin            #+#    #+#             */
/*   Updated: 2024/10/01 13:36:22 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_node	*pop_stack(t_stack *stack)
{
	t_node	*temp;

	if (stack->size == 0 || stack->node == NULL)
		return (NULL);
	temp = stack->node;
	stack->node = stack->node->next;
	stack->size--;
	return (temp);
}

void	push_stack(t_stack *stack1, t_stack *stack2)
{
	t_node	*t_node;

	t_node = pop_stack(stack2);
	if (stack1->size == 0)
	{
		t_node->next = NULL;
		stack1->node = t_node;
	}
	else
	{
		t_node->next = stack1->node;
		stack1->node = t_node;
	}
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
