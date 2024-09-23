/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:26:20 by glevin            #+#    #+#             */
/*   Updated: 2024/09/23 17:03:49 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>

t_stack *init_stack()
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return NULL;

    stack->frame = NULL;
    stack->size = 0;

    return stack;
}

t_frame *pop_stack(t_stack *stack)
{
    t_frame *temp;

    temp = stack->frame;
    stack->frame = stack->frame->next;
    return temp;
}

void free_stack(t_stack *stack)
{
    t_frame *next;
    t_frame *current;

    current = stack->frame;
    next = current->next;
    while (next)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

t_stack *push_to_stack(t_stack *stack, int data)
{
    t_frame *new_frame;

    printf("Data: %d\n", data);
    new_frame = (t_frame *)malloc(sizeof(t_frame));
    if (!new_frame)
        NULL;

    new_frame->data = data;
    new_frame->next = stack->frame;
    stack->frame = new_frame;
    return stack;
}

t_stack *add_frame(t_stack *stack, int data)
{
    t_frame *new_frame;
    t_frame *last;

    printf("Data: %d\n", data);
    new_frame = (t_frame *)malloc(sizeof(t_frame));
    if (!new_frame)
        NULL;

    new_frame->data = data;
    new_frame->next = NULL;
    last = stack->frame;
    if (last == NULL)
    {
        stack->frame = new_frame;
        return stack;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_frame;
    return stack;
}

t_stack *read_input(t_stack *stack, char *args)
{
    char **str;
    int i;

    i = 0;
    str = ft_split(args, ' ');
    while (str[i])
    {
        stack = add_frame(stack, ft_atoi(str[i]));
        i++;
        stack->size++;
    }
    return stack;
}

void print_ll(t_frame *head)
{
    while (head)
    {
        ft_printf("%d\n", head->data);
        head = head->next;
    }
}

int main(int argc, char **argv)
{
    t_stack *stack1;
    t_stack *stack2;

    if (argc != 2)
        return -1;

    stack1 = init_stack();
    stack2 = init_stack();

    if (stack1 == NULL || stack2 == NULL)
        return -1;

    read_input(stack1, argv[1]);
    free_stack(stack1);
    free_stack(stack2);
    return 1;
}
