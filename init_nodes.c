/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:22:03 by glevin            #+#    #+#             */
/*   Updated: 2024/09/26 17:22:17 by glevin           ###   ########.fr       */
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
		ft_printf("index: %d\n", i);
		current->index = i;
		if (i <= median)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		i++;
	}
}

t_node	*get_max_node(t_node *s)
{
	t_node	*max_node;

	max_node = s;
	while (s)
	{
		if (max_node->data < s->data)
			max_node = s;
		s = s->next;
	}
	return (max_node);
}

void	set_dec_targets(t_node *s1, t_node *s2)
{
	t_node	*current_s2;
	t_node	*target_node;
	int		closest_min;

	while (s1)
	{
		current_s2 = s2;
		closest_min = INT_MIN;
		while (current_s2)
		{
			if (current_s2->data > closest_min && current_s2->data < s1->data)
			{
				target_node = current_s2;
				closest_min = current_s2->data;
			}
			current_s2 = current_s2->next;
		}
		if (closest_min == INT_MIN)
			s1->target = get_max_node(s2);
		else
			s1->target = target_node;
		current_s2 = s2;
		s1 = s1->next;
	}
}

int get_bigger_val(int x, int y)
{
	if (x > y)
		return x;
	else if (y > x)
		return y;
	else
		return x;
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

void	init_nodes(t_stack *stack1, t_stack *stack2)
{
	set_index(stack1);
	set_index(stack2);
	set_dec_targets(stack1->node, stack2->node);
	calc_costs(stack1, stack2);
	// get_cheapeast(stack1);
}