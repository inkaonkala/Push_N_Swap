/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_with_median.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:38:19 by iniska            #+#    #+#             */
/*   Updated: 2024/01/03 16:48:10 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_median(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_pair)
{
	while (*b != cheapest_pair->target && *a != cheapest_pair)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rr_median(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest_pair)
{
	while (*b != cheapest_pair->target && *a != cheapest_pair)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}
