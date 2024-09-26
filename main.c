/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:26:20 by glevin            #+#    #+#             */
/*   Updated: 2024/09/26 20:23:02 by glevin           ###   ########.fr       */
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
			ra(stack);
		if (max_node->index == 0)
			rra(stack);
	}
	if (!is_stack_sorted(stack))
		sa(stack);
}

get_cheapest_node(t_stack *stack)
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
}

int	get_smaller_val(int x, int y)
{
	if (x <= y)
		return (x);
	else
		return (y);
}

void	conduct_single_rot(t_stack *stack, int n, int s_name)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (s_name == 1)
			ra(stack);
		else
			rb(stack);
		i++;
	}
}

void	transfer_node(t_stack *stack1, t_stack *stack2)
{
	t_node	*node;
	t_node	*target;
	int		shared_rots;
	int		single_rots;
	int		i;

	node = get_cheapest_node(stack1);
	target = node->target;
	if ((node->above_median && target->above_median))
	{
		shared_rots = get_smaller_val(node->index, target->index);
		if ((node->index - shared_rots) > 0)
		{
			single_rots = node->index - shared_rots;
			i = 0;
			while (i < single_rots)
			{
				ra(stack1);
				i++;
			}
		}
		else
		{
			single_rots = target->index - shared_rots;
			i = 0;
			while (i < single_rots)
			{
				rb(stack1);
				i++;
			}
		}
	}
	else if (!node->above_median && !target->above_median)
	{
		shared_rots = get_bigger_val(node->index, target->index);
	}
}

void	sort_stack(t_stack *stack1, t_stack *stack2)
{
	pb(stack2, stack1);
	pb(stack2, stack1);
	while (stack1->size != 3)
	{
		init_nodes(stack1, stack2);
		transfer_node(stack1, stack2);
	}
	if (stack1->size == 3 && !is_stack_sorted(stack1))
		sort_3_stack(stack1);
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
