/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:53:43 by glevin            #+#    #+#             */
/*   Updated: 2024/10/01 13:56:16 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	transfer_node(t_stack *stack1, t_stack *stack2)
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

void	sort_stack(t_stack *stack1, t_stack *stack2)
{
	if (stack1->size <=1)
		return;
	pb(stack2, stack1);
	pb(stack2, stack1);
	while (stack1->size > 0)
	{
		init_nodes_a_to_b(stack1, stack2);
		transfer_node(stack1, stack2);
	}
	set_index(stack2);
	rotate_max_to_top(stack2);
	while (stack2->size > 0)
		pa(stack1, stack2);
}
