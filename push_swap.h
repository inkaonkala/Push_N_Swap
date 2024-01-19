/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:02:24 by iniska            #+#    #+#             */
/*   Updated: 2024/01/09 11:28:43 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>  //do i need this?
# include <limits.h> // for MIN and MAX
# include <stdbool.h> //for bools
# include <stdio.h> // FOR TESTING, REMOVE!!!
# include <stdlib.h> //for malloc
# include "/Users/iniska/my_libft/libft.h"

//struct!
typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					pushcost;
	bool				median;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				main(int argc, char **argv);

// handling the list
char			**stack_it(char *nmb, char s);
void			init_stack(t_stack_node **a, char **stack);
void			push_prep(t_stack_node **stack, t_stack_node *top,
					char stack_name);
void			top_min(t_stack_node **a);

// handling node

t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_tale(t_stack_node *stack);
t_stack_node	*get_the_cheapest(t_stack_node *stack);

void			current_index(t_stack_node	*stack);
void			set_cheapest(t_stack_node *stack);

//a_node
void			cost_for_a(t_stack_node	*a, t_stack_node *b);
void			set_target_a(t_stack_node *a, t_stack_node *b);
void			a_to_b(t_stack_node **a, t_stack_node **b);

//b_node
void			cost_for_b(t_stack_node *a, t_stack_node *b);
void			b_to_a(t_stack_node **a, t_stack_node **b);
void			set_target_b(t_stack_node *a, t_stack_node *b);

// sorting:
bool			sorted(t_stack_node	*stack);
void			sort_three(t_stack_node **a);
int				stack_len(t_stack_node *stack);
void			sort_it(t_stack_node **a, t_stack_node **b);
int				stack_len(t_stack_node *stack);

void			push_price_a(t_stack_node *a, t_stack_node *b);
void			push_price_b(t_stack_node *a, t_stack_node *b);

void			push_prep(t_stack_node **stack, t_stack_node *top,
					char stack_name);

// swap n push:
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

void			rr_median(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_pair);
void			rev_rr_median(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_pair);

void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

// errors and free:
bool			number(char i);
void			free_stack(t_stack_node **stack);
bool			duplicates(t_stack_node **stack);
void			stop_it(t_stack_node **a);

#endif
