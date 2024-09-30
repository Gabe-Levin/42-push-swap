/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:26:20 by glevin            #+#    #+#             */
/*   Updated: 2024/09/30 16:52:57 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_stack_sorted(t_stack *stack)
{
	t_node	*current;
	t_node	*prev;

	prev = stack->node;
	current = stack->node->next;
	while (current)
	{
		if (prev->data > current->data)
			return (0);
		prev = current;
		current = current->next;
	}
	return (1);
}

void	sort_3_stack(t_stack *stack)
{
	t_node	*max_node;

	max_node = get_max_node(stack->node);
	if (max_node->index != 2)
	{
		if (max_node->index == 1)
			rra(stack);
		if (max_node->index == 0)
			ra(stack);
	}
	if (!is_stack_sorted(stack))
		sa(stack);
}

t_node	*get_cheapest_node(t_stack *stack)
{
	t_node	*current;
	t_node	*cheapest;

	current = stack->node;
	cheapest = stack->node;
	while (current)
	{
		if (current->push_cost < cheapest->push_cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}

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
		while(i < rots)
		{
			rb(stack);
			i++;
		}
	}
	else
	{
		rots = stack->size - max_node->index;
		while(i < rots)
		{
			rrb(stack);
			i++;
		}
	}
}

void	sort_stack(t_stack *stack1, t_stack *stack2)
{
	pb(stack2, stack1);
	pb(stack2, stack1);
	while (stack1->size > 0)
	{
		init_nodes_a_to_b(stack1, stack2);
		transfer_node_a_to_b(stack1, stack2);
	}
	// if (!is_stack_sorted(stack1))
	// {
	// 	set_index(stack1);
	// 	sort_3_stack(stack1);
	// }
	set_index(stack2);
	rotate_max_to_top(stack2);
	while (stack2->size > 0)
		pa(stack1, stack2);
	// while (stack2->size > 0)
	// {
	// 	init_nodes_b_to_a(stack2, stack1);
	// 	transfer_node_a_to_b(stack2, stack1);
	// }
}

int	main(int argc, char **argv)
{
	t_stack	*stack1;
	t_stack	*stack2;

	stack1 = init_stack();
	stack2 = init_stack();
	if (stack1 == NULL || stack2 == NULL)
		return (-1);
	read_input(stack1, argc, argv);
	sort_stack(stack1, stack2);
	// ft_printf("STACK1: \n");
	// print_ll(stack1->node);
	// ft_printf("STACK2: \n");
	// print_ll(stack2->node);
	free_stack(stack1);
	free_stack(stack2);
	return (1);
}
