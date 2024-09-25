/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:26:38 by glevin            #+#    #+#             */
/*   Updated: 2024/09/25 13:52:25 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "masterLib/masterLib.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	target;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*node;
	int				size;
}					t_stack;

t_node				*pop_stack(t_stack *stack);
t_stack				*push_to_stack(t_stack *stack, int data);
t_stack				*init_stack(void);
t_stack				*add_node(t_stack *stack, int data);
void				free_stack(t_stack *stack);
t_stack				*push_to_stack(t_stack *stack, int data);
t_node				*pop_stack(t_stack *stack);
t_stack				*read_input(t_stack *stack, char *args);

void				print_ll(t_node *head);

#endif