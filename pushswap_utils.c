/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:13:01 by glevin            #+#    #+#             */
/*   Updated: 2024/09/29 17:04:04 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
