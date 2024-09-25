/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:57:43 by glevin            #+#    #+#             */
/*   Updated: 2024/09/25 13:34:31 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_stack *read_input(t_stack *stack, char *args)
{
    char **str;
    int i;

    i = 0;
    str = ft_split(args, ' ');
    while (str[i])
    {
        stack = add_node(stack, ft_atoi(str[i]));
        i++;
        stack->size++;
    }
    return stack;
}