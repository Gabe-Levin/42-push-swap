/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:26:38 by glevin            #+#    #+#             */
/*   Updated: 2024/09/17 16:19:47 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

# include "masterLib/masterLib.h"

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

#endif