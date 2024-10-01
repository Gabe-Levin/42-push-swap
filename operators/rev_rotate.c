/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:15:01 by glevin            #+#    #+#             */
/*   Updated: 2024/10/01 12:44:31 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	rev_rotate_stack(t_stack *stack)
{
	t_node	*last;
	t_node	*second_to_last;

	if (stack->node == NULL || stack->node->next == NULL)
		return ;
	last = stack->node;
	second_to_last = NULL;
	while (last->next)
	{
		second_to_last = last;
		last = last->next;
	}
	last->next = stack->node;
	stack->node = last;
	second_to_last->next = NULL;
}

void	rra(t_stack *stack1)
{
	ft_printf("rra\n");
	rev_rotate_stack(stack1);
}

void	rrb(t_stack *stack2)
{
	ft_printf("rrb\n");
	rev_rotate_stack(stack2);
}

void	rrr(t_stack *stack1, t_stack *stack2)
{
	ft_printf("rrr\n");
	rev_rotate_stack(stack1);
	rev_rotate_stack(stack2);
}
