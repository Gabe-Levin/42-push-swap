/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:26:20 by glevin            #+#    #+#             */
/*   Updated: 2024/09/17 16:45:13 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>

t_frame *init_frame(void)
{
    t_frame *head;

    head = (t_frame *)malloc(sizeof(t_frame));
    if (!head)
        return NULL;
    
    head->data = 0;
    head->next = NULL;
    
    return head;
}
t_stack *init_stack(t_frame *head)
{
    t_stack *stack;
    
    stack = (t_stack *)malloc(sizeof(t_stack));
    if(!stack)
        return NULL;

    stack->frame = head;
    stack->size = 1;

    return stack;
}

void free_stack(t_stack *stack)
{
    t_frame *next;
    t_frame *current;

    current = stack->frame;
    while(next)
    {
        next = current -> next;
        free(current);
        current = next;
    }
}

t_stack *push_to_stack(t_stack *stack, int data)
{
    t_frame *new_frame;

    new_frame = (t_frame *)malloc(sizeof(t_frame));
    if(!new_frame)
        NULL;
    
    new_frame->data = data;
    new_frame->next = stack->frame;
    stack->frame = new_frame;
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
        stack = push_to_stack(stack, ft_atoi(str[i]));
        i++;
    }
    return stack;
}

int main(int argc, char **argv)
{
    t_frame *head1; 
    t_frame *head2;
    t_stack *stack1; 
    t_stack *stack2;

    if (argc != 2)
        return -1;

    head1 = init_frame();
    head2 = init_frame();
    stack1 = init_stack(head1);
    stack2 = init_stack(head2);
    
    if (head1 == NULL || head2 == NULL|| stack1 == NULL|| stack2 == NULL)
        return -1;

    read_input(stack1, argv[1]);
    free_stack(stack1);
    free_stack(stack2);
    return 1;
}
