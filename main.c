/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:26:20 by glevin            #+#    #+#             */
/*   Updated: 2024/09/29 19:22:40 by glevin           ###   ########.fr       */
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
	t_node	*cheapest;
	t_node	*target;
	int		shared_rots;
	int		single_rots;
	int		i;

	cheapest = get_cheapest_node(stack1);
	target = cheapest->target;
	if ((cheapest->above_median && target->above_median))
	{
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
	else if (!cheapest->above_median && !target->above_median)
	{
		if (cheapest->index > target->index)
			shared_rots = stack1->size - cheapest->index;
		else
			shared_rots = stack2->size - target->index;
		printf("cheapest->index: %d\n", cheapest->index);
		printf("stack1->size: %d\n", stack1->size);
		printf("target->index: %d\n", target->index);
		printf("stack2->size: %d\n", stack2->size);
		printf("shared_rots: %d\n", shared_rots);
		i = 0;
		while (++i <= shared_rots)
		{
			rrr(stack1, stack2);
		}
		if ((stack1->size - cheapest->index) > (stack2->size - target->index))
		{
			single_rots = (stack1->size - cheapest->index) - shared_rots;
			i = 0;
			// printf("cheapest->index: %d\n", cheapest->index);
			// printf("target->index: %d\n", target->index);
			// printf("single_rots: %d\n", single_rots);
			while (++i <= single_rots)
				rra(stack1);
		}
		else
		{
			single_rots = (stack2->size - target->index) - shared_rots;
			printf("cheapest->index: %d\n", cheapest->index);
			printf("target->index: %d\n", target->index);
			printf("single_rots: %d\n", single_rots);
			i = 0;
			while (++i <= single_rots)
			{
				printf("+++\n");
				rrb(stack2);
			}
		}
	}
	else
	{
		if (cheapest->above_median)
		{
			i = 0;
			while (++i <= cheapest->index)
				ra(stack1);
		}
		else
		{
			i = 0;
			while (++i <= (stack1->size - cheapest->index))
			{
				printf("---\n");
				rra(stack1);
			}
		}
		if (target->above_median)
		{
			i = 0;
			while (++i <= target->index)
				rb(stack2);
		}
		else
		{
			i = 0;
			while (++i <= (stack2->size - target->index))
				rrb(stack2);
		}
	}
	pb(stack2, stack1);
}

void	sort_stack(t_stack *stack1, t_stack *stack2)
{
	pb(stack2, stack1);
	pb(stack2, stack1);
	while (stack1->size > 3)
	{
		init_nodes(stack1, stack2);
		transfer_node(stack1, stack2);
	}
	if (!is_stack_sorted(stack1))
	{
		printf("HEREERER");
		set_index(stack1);
		sort_3_stack(stack1);
	}
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
