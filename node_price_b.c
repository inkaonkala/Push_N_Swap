/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_price_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:29:02 by iniska            #+#    #+#             */
/*   Updated: 2024/01/03 15:29:27 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*a_now;
	t_stack_node	*target;
	long			best_match_nbr;

	while (b)
	{
		best_match_nbr = LONG_MAX;
		a_now = a;
		while (a_now)
		{
			if (a_now->nbr > b->nbr && a_now->nbr < best_match_nbr)
			{
				best_match_nbr = a_now->nbr;
				target = a_now;
			}
			a_now = a_now->next;
		}
		if (best_match_nbr == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	b_to_a(t_stack_node **a, t_stack_node **b)
{
	push_prep(a, (*b)->target, 'a');
	pa(a, b);
}
