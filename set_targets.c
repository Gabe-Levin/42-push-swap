/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:29:35 by glevin            #+#    #+#             */
/*   Updated: 2024/10/01 12:37:29 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

t_node	*get_min_node(t_node *s)
{
	t_node	*min_node;

	min_node = s;
	while (s)
	{
		if (min_node->data > s->data)
			min_node = s;
		s = s->next;
	}
	return (min_node);
}

void	set_decending_targets(t_node *s1, t_node *s2)
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

void	set_ascending_targets(t_node *s1, t_node *s2)
{
	t_node	*current_s2;
	t_node	*target_node;
	int		closest_max;

	while (s1)
	{
		current_s2 = s2;
		closest_max = INT_MAX;
		while (current_s2)
		{
			if (current_s2->data < closest_max && current_s2->data < s1->data)
			{
				target_node = current_s2;
				closest_max = current_s2->data;
			}
			current_s2 = current_s2->next;
		}
		if (closest_max == INT_MAX)
			s1->target = get_min_node(s2);
		else
			s1->target = target_node;
		current_s2 = s2;
		s1 = s1->next;
	}
}
