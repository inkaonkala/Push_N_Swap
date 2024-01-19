/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotaters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:32:04 by iniska            #+#    #+#             */
/*   Updated: 2023/12/27 10:32:24 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	rotaters(t_stack_node **stack)
{
	t_stack_node	*tale;

	if (!*stack || !(*stack)->next)
		return (false);
	tale = find_tale(*stack);
	tale->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tale->next->prev = tale;
	tale->next->next = NULL;
	return (true);
}

void	ra(t_stack_node **a)
{
	if (rotaters(a))
		ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	if (rotaters(b))
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	if (rotaters(a))
		if (rotaters(b))
			ft_printf("rr\n");
}
