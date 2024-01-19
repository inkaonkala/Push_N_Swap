/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:04:44 by iniska            #+#    #+#             */
/*   Updated: 2023/12/18 11:07:41 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_n_swap(t_stack_node *a, t_stack_node *b)
{
	if (stack_len(a) == 2)
		sa(&a);
	else if (stack_len(a) == 3)
			sort_three(&a);
	else
		sort_it(&a, &b);
	free_stack(&a);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2 && argv[1] != NULL)
	{
		argv = stack_it(argv[1], ' ');
		init_stack(&a, argv);
	}
	else
		init_stack(&a, argv + 1);
	if (duplicates(&a))
		stop_it(&a);
	if (!sorted(a))
		push_n_swap(a, b);
	else
		free_stack(&a);
	return (0);
}
