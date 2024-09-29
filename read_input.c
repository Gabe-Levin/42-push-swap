/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:57:43 by glevin            #+#    #+#             */
/*   Updated: 2024/09/29 18:03:05 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_stack	*read_single_string(t_stack *stack, char *args)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_split(args, ' ');
	while (str[i])
	{
		stack = add_node(stack, ft_atoi(str[i]));
		i++;
		stack->size++;
	}
	return (stack);
}

t_stack	*read_multiple_args(t_stack *stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		stack = add_node(stack, ft_atoi(argv[i]));
        stack->size++;
		i++;
	}
	return (stack);
}

t_stack	*read_input(t_stack *stack, int argc, char **argv)
{
	if (argc == 2)
		stack = read_single_string(stack, argv[1]);
	else
		stack = read_multiple_args(stack, argc, argv);
	return (stack);
}