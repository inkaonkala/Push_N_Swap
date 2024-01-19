/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:36:05 by iniska            #+#    #+#             */
/*   Updated: 2023/12/27 09:36:51 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	swappers(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return (false);
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
	return (true);
}

void	sa(t_stack_node **a)
{
	if (swappers(a))
		ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	if (swappers(b))
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	if (swappers(a) || swappers(b))
		ft_printf("ss\n");
}
