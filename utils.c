/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:13:01 by glevin            #+#    #+#             */
/*   Updated: 2024/09/23 16:55:23 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void swap_stack(t_stack *stack)
{
  t_frame *temp;

  if (stack->size <= 1)
    return;

  temp = stack->frame ;
  stack->frame = stack->frame->next;
  temp->next = stack->frame->next;
  stack->frame->next = temp;
}

void ss(t_stack *stack1, t_stack *stack2)
{
  swap_stack(stack1);
  swap_stack(stack2);
}

void push_stack(t_stack *stack1, t_stack *stack2)
{
  t_frame *temp;

  temp = pop_stack(stack2);
  if(stack1->size == 0)
    stack1->frame = temp;
  else
    push_to_stack(stack1, temp->data);
}

void rotate_stack(t_stack *stack)
{
  t_frame *temp;
  t_frame *next;

  temp = stack->frame;
  stack->frame = stack->frame->next;
  next = stack->frame->next;
  while (next->next)
    next = next->next;
  next->next = temp;
  next->next->next = NULL;
}

void rr(t_stack *stack1, t_stack *stack2)
{
  rotate_stack(stack1);
  rotate_stack(stack2);
}

void rev_rotate_stack(t_stack *stack)
{
  t_frame *next;

  next = stack->frame->next;
  while (next->next->next)
    next = next->next;
  push_to_stack(stack, next->next->data);
  next->next = NULL;
}

void rrr(t_stack *stack1, t_stack *stack2)
{
  rev_rotate_stack(stack1);
  rev_rotate_stack(stack2);
}

