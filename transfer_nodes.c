/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:29:35 by glevin            #+#    #+#             */
/*   Updated: 2024/10/01 12:37:54 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_smaller_val(int x, int y)
{
	if (x <= y)
		return (x);
	else
		return (y);
}

void	transfer_node_a_to_b(t_stack *stack1, t_stack *stack2)
{
	t_node	*cheapest;
	t_node	*target;

	cheapest = get_cheapest_node(stack1);
	target = cheapest->target;
	if ((cheapest->above_median && target->above_median))
		rot_nodes_above_median(stack1, stack2, cheapest, target);
	else if (!cheapest->above_median && !target->above_median)
		rot_nodes_below_median(stack1, stack2, cheapest, target);
	else
		rot_nodes_individually(stack1, stack2, cheapest, target);
	pb(stack2, stack1);
}

void	transfer_node_b_to_a(t_stack *stack1, t_stack *stack2)
{
	t_node	*cheapest;
	t_node	*target;

	cheapest = get_cheapest_node(stack1);
	target = cheapest->target;
	if ((cheapest->above_median && target->above_median))
		rot_nodes_above_median(stack1, stack2, cheapest, target);
	else if (!cheapest->above_median && !target->above_median)
		rot_nodes_below_median(stack1, stack2, cheapest, target);
	else
		rot_nodes_individually(stack1, stack2, cheapest, target);
	pb(stack2, stack1);
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
