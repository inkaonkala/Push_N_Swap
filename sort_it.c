/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:49:36 by iniska            #+#    #+#             */
/*   Updated: 2023/12/29 11:50:12 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_min(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->median)
			ra(a);
		else
			rra(a);
	}
}

void	push_prep(t_stack_node **stack, t_stack_node *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top->median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	push_price_b(t_stack_node *a, t_stack_node *b)
{
	current_index(b);
	current_index(a);
	set_target_b(a, b);
}

void	push_price_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_for_a(a, b);
	set_cheapest(a);
}

void	sort_it(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_len(*a);
	if (len-- > 3 && !sorted(*a))
		pb(b, a);
	if (len-- > 3 && !sorted(*a))
		pb(b, a);
	while (len-- > 3 && !sorted(*a))
	{
		push_price_a(*a, *b);
		a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		push_price_b(*a, *b);
		b_to_a(a, b);
	}
	current_index(*a);
	top_min(a);
}
