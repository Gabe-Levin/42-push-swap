/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:26:38 by glevin            #+#    #+#             */
/*   Updated: 2024/09/23 16:11:21 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

# include "masterLib/masterLib.h"
#include <stdio.h>

typedef struct s_frame
{
  int data;
  struct s_frame *next;
} t_frame;

typedef struct s_stack
{
  t_frame *frame;
  int size;
} t_stack;

t_frame *pop_stack(t_stack *stack);
t_stack *push_to_stack(t_stack *stack, int data);

#endif