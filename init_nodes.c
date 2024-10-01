/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:22:03 by glevin            #+#    #+#             */
/*   Updated: 2024/10/01 12:38:02 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_index(t_stack *stack)
{
	int		i;
	int		median;
	t_node	*current;

	i = 0;
	median = stack->size / 2 - 1;
	current = stack->node;
	while (current)
	{
		current->index = i;
		if (i <= median)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		i++;
	}
}

int	get_bigger_val(int x, int y)
{
	if (x > y)
		return (x);
	else if (y > x)
		return (y);
	else
		return (x);
}

void	calc_costs(t_stack *stack1, t_stack *stack2)
{
	int		rot_cost_a;
	int		rot_cost_b;
	t_node	*current;

	rot_cost_a = 0;
	rot_cost_b = 0;
	current = stack1->node;
	while (current)
	{
		if (current->above_median)
			rot_cost_a = current->index;
		else
			rot_cost_a = stack1->size - current->index;
		if (current->target->above_median)
			rot_cost_b = current->target->index;
		else
			rot_cost_b = stack2->size - current->target->index;
		if ((current->above_median && current->target->above_median)
			|| (!current->above_median && !current->target->above_median))
			current->push_cost = get_bigger_val(rot_cost_b, rot_cost_a);
		else
			current->push_cost = rot_cost_b + rot_cost_a;
		current = current->next;
	}
}

void	init_nodes_a_to_b(t_stack *stack1, t_stack *stack2)
{
	set_index(stack1);
	set_index(stack2);
	set_decending_targets(stack1->node, stack2->node);
	calc_costs(stack1, stack2);
}

void	init_nodes_b_to_a(t_stack *stack1, t_stack *stack2)
{
	set_index(stack1);
	set_index(stack2);
	set_ascending_targets(stack2->node, stack1->node);
	calc_costs(stack2, stack1);
}
