/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:12:10 by glevin            #+#    #+#             */
/*   Updated: 2024/10/01 12:44:38 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->node == NULL || stack->node->next == NULL)
		return ;
	first = stack->node;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->node = second;
}

void	sa(t_stack *stack1)
{
	ft_printf("sa\n");
	swap_stack(stack1);
}

void	sb(t_stack *stack2)
{
	ft_printf("sb\n");
	swap_stack(stack2);
}

void	ss(t_stack *stack1, t_stack *stack2)
{
	ft_printf("ss\n");
	swap_stack(stack1);
	swap_stack(stack2);
}
