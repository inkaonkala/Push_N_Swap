/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_price_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:49:09 by iniska            #+#    #+#             */
/*   Updated: 2024/01/03 14:11:57 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node	*stack)
{
	int	node_nbr;
	int	is_median;

	if (!stack)
		return ;
	node_nbr = 0;
	is_median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = node_nbr;
		if (node_nbr <= is_median)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next;
		node_nbr++;
	}
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*b_now;
	t_stack_node	*target;
	long			best_match_nbr;

	while (a)
	{
		best_match_nbr = LONG_MIN;
		b_now = b;
		while (b_now)
		{
			if (b_now->nbr < a->nbr && b_now->nbr > best_match_nbr)
			{
				best_match_nbr = b_now->nbr;
				target = b_now;
			}
			b_now = b_now->next;
		}
		if (best_match_nbr == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	cost_for_a(t_stack_node	*a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->pushcost = a->index;
		if (!(a->median))
			a->pushcost = len_a - (a->index);
		if (a->target->median)
			a->pushcost += a->target->index;
		else
			a->pushcost += len_b - (a->target->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			im_cheap;
	t_stack_node	*cheapest_pair;

	if (!stack)
		return ;
	im_cheap = LONG_MAX;
	while (stack)
	{
		if (stack->pushcost < im_cheap)
		{
			im_cheap = stack->pushcost;
			cheapest_pair = stack;
		}
		stack = stack->next;
	}
	cheapest_pair->cheapest = true;
}

void	a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_pair;

	cheapest_pair = get_the_cheapest(*a);
	if (cheapest_pair->median && cheapest_pair->target->median)
		rr_median(a, b, cheapest_pair);
	else if (!(cheapest_pair->target->median) && !(cheapest_pair->median))
		rev_rr_median(a, b, cheapest_pair);
	push_prep(a, cheapest_pair, 'a');
	push_prep(b, cheapest_pair->target, 'b');
	pb(b, a);
}
