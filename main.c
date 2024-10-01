/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:26:20 by glevin            #+#    #+#             */
/*   Updated: 2024/10/01 12:39:33 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	free_stack(stack1);
	free_stack(stack2);
	return (1);
}
