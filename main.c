/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:26:20 by glevin            #+#    #+#             */
/*   Updated: 2024/09/25 13:58:24 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_index(t_stack *stack)
{
	int		i;
	int		median;
	t_node	*current;

	i = 0;
	median = stack->size / 2;
	current = stack->node;
	while (current)
	{
		current->index = i;
		if (i <= median)
			current->above_median = true;
		else
			current->above_median = true;
		current = current->next;
		i++;
	}
}

t_node *get_max_node(t_node *s)
{
    t_node *max_node;
    
    max_node = s;
    while(s)
    {
        if (max_node->data > s->data)
            max_node = s;
        s = s->next;
    }
    return max_node;
}

void	set_targets_decending(t_node *s1, t_node *s2)
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

void	init_nodes(t_stack *stack1, t_stack *stack2)
{
	set_index(stack1->node);
	set_index(stack2->node);
	set_targets(stack1, stack2);
	// calc_cost(stack2, stack2);
	// get_cheapeast(stack1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack1;
	t_stack	*stack2;

	if (argc != 2)
		return (-1);
	stack1 = init_stack();
	stack2 = init_stack();
	if (stack1 == NULL || stack2 == NULL)
		return (-1);
	read_input(stack1, argv[1]);
	free_stack(stack1);
	free_stack(stack2);
	return (1);
}
