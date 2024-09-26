/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:26:38 by glevin            #+#    #+#             */
/*   Updated: 2024/09/26 18:01:24 by glevin           ###   ########.fr       */
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
	struct s_node	*target;
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
void				set_index(t_stack *stack);
t_node				*get_max_node(t_node *s);
int					get_bigger_val(int x, int y);
void				calc_costs(t_stack *stack1, t_stack *stack2);
void				init_nodes(t_stack *stack1, t_stack *stack2);

void				sa(t_stack *stack1);
void				sb(t_stack *stack2);
void				ss(t_stack *stack1, t_stack *stack2);
void				pa(t_stack *stack1, t_stack *stack2);
void				pb(t_stack *stack2, t_stack *stack1);
void				ra(t_stack *stack1);
void				rb(t_stack *stack2);
void				rr(t_stack *stack1, t_stack *stack2);
void				rra(t_stack *stack1);
void				rrb(t_stack *stack2);
void				rrr(t_stack *stack1, t_stack *stack2);

void				set_dec_targets(t_node *s1, t_node *s2);
void				print_ll(t_node *head);

#endif