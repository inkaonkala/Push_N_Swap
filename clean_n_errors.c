/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_n_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:56:55 by iniska            #+#    #+#             */
/*   Updated: 2023/12/29 10:58:25 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*stop_it(t_stack_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(0);
}

bool	number(char i)
{
	if ((i >= '0' && i <= '9') || (i == '-' ) || (i == '+'))
		return (true);
	return (false);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*nodes;

	if (!stack)
		return ;
	nodes = *stack;
	while (nodes)
	{
		tmp = nodes->next;
		nodes->nbr = 0;
		free(nodes);
		nodes = tmp;
	}
	*stack = NULL;
}

bool	duplicates(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*nodes;
	int				i;

	i = 0;
	if (!stack || !(*stack))
		return (false);
	current = *stack;
	while (current)
	{
		nodes = current->next;
		while (nodes)
		{
			if (current->nbr == nodes->nbr)
				i = 2;
			nodes = nodes->next;
		}
		current = current->next;
	}
	if (i == 2)
		stop_it(stack);
	return (false);
}
