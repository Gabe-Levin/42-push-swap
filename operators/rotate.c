/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:13:55 by glevin            #+#    #+#             */
/*   Updated: 2024/10/01 12:44:34 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	rotate_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*next;

	if (stack->node == NULL || stack->node->next == NULL)
		return ;
	temp = stack->node;
	stack->node = stack->node->next;
	next = stack->node->next;
	while (next->next)
		next = next->next;
	next->next = temp;
	next->next->next = NULL;
}

void	ra(t_stack *stack1)
{
	ft_printf("ra\n");
	rotate_stack(stack1);
}

void	rb(t_stack *stack2)
{
	ft_printf("rb\n");
	rotate_stack(stack2);
}

void	rr(t_stack *stack1, t_stack *stack2)
{
	ft_printf("rr\n");
	rotate_stack(stack1);
	rotate_stack(stack2);
}