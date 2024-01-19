/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotaters_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:32:36 by iniska            #+#    #+#             */
/*   Updated: 2023/12/27 10:33:10 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	rotaters_rev(t_stack_node **stack)
{
	t_stack_node	*tale;

	if (!stack || !(*stack)->next)
		return (false);
	tale = find_tale(*stack);
	tale->prev->next = NULL;
	tale->next = *stack;
	tale->prev = NULL;
	*stack = tale;
	tale->next->prev = tale;
	return (true);
}

void	rra(t_stack_node **a)
{
	if (rotaters_rev(a))
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	if (rotaters_rev(b))
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	if (rotaters_rev(a))
		if (rotaters_rev(b))
			ft_printf("rrr\n");
}
