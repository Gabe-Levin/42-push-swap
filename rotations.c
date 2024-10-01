/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:48:50 by glevin            #+#    #+#             */
/*   Updated: 2024/10/01 16:30:40 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	rot_nodes_above_median(t_stack *stack1, t_stack *stack2,
		t_node *cheapest, t_node *target)
{
	int	shared_rots;
	int	single_rots;
	int	i;

	shared_rots = get_smaller_val(cheapest->index, target->index);
	i = 0;
	while (++i <= shared_rots)
		rr(stack1, stack2);
	if ((cheapest->index - shared_rots) > 0)
	{
		single_rots = cheapest->index - shared_rots;
		i = 0;
		while (++i <= single_rots)
			ra(stack1);
	}
	else
	{
		single_rots = target->index - shared_rots;
		i = 0;
		while (++i <= single_rots)
			rb(stack2);
	}
}

void	rot_nodes_below_median(t_stack *stack1, t_stack *stack2,
		t_node *cheapest, t_node *target)
{
	int	shared_rots;
	int	single_rots;
	int	i;

	if ((stack1->size - cheapest->index) < (stack2->size - target->index))
		shared_rots = stack1->size - cheapest->index;
	else
		shared_rots = stack2->size - target->index;
	i = 0;
	while (++i <= shared_rots)
		rrr(stack1, stack2);
	if ((stack1->size - cheapest->index) > (stack2->size - target->index))
	{
		single_rots = (stack1->size - cheapest->index) - shared_rots;
		i = 0;
		while (++i <= single_rots)
			rra(stack1);
	}
	else
	{
		single_rots = (stack2->size - target->index) - shared_rots;
		i = 0;
		while (++i <= single_rots)
			rrb(stack2);
	}
}

void	rot_nodes_individually(t_stack *stack1, t_stack *stack2,
		t_node *cheapest, t_node *target)
{
	int	i;

	i = 0;
	if (cheapest->above_median)
	{
		while (++i <= cheapest->index)
			ra(stack1);
	}
	else
	{
		while (++i <= (stack1->size - cheapest->index))
			rra(stack1);
	}
	i = 0;
	if (target->above_median)
	{
		while (++i <= target->index)
			rb(stack2);
	}
	else
	{
		while (++i <= (stack2->size - target->index))
			rrb(stack2);
	}
}

void	rotate_max_to_top(t_stack *stack)
{
	t_node	*max_node;
	int		rots;
	int		i;

	max_node = get_max_node(stack->node);
	i = 0;
	if (max_node->above_median == true)
	{
		rots = max_node->index;
		while (i < rots)
		{
			rb(stack);
			i++;
		}
	}
	else
	{
		rots = stack->size - max_node->index;
		while (i < rots)
		{
			rrb(stack);
			i++;
		}
	}
}
