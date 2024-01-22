/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:42:01 by iniska            #+#    #+#             */
/*   Updated: 2023/12/18 15:43:15 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_latoi(const char *str)
{
	long	n;
	int		t;

	n = 0;
	t = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			t = -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9'))
	{
		n *= 10;
		n += *str - '0';
		str++;
	}
	return (n * t);
}

static void	save_node(t_stack_node **stack, int num)
{
	t_stack_node	*node;
	t_stack_node	*tale;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = num;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		tale = find_tale(*stack);
		tale->next = node;
		node->prev = tale;
	}
}

void	init_stack(t_stack_node **a, char **argv)
{
	long	num;
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (number(argv[i][j]))
		{
			num = ft_latoi(argv[i] + j);
			if (num > INT_MAX || num < INT_MIN)
				stop_it(a);
			save_node(a, (int)num);
			while (number(argv[i][j]))
				j++;
		}
		else
			stop_it(a);
		i++;
	}
}

static void	set_nodes(t_stack_node *new_node, t_stack_node *head,
						t_stack_node *current)
{
	if (head == NULL)
	{
		head = new_node;
		current = new_node;
	}
	else
	{
		current->next = new_node;
		current = new_node;
	}
}

char	**stack_it(char *nmb, char s)
{
	char			**numbers;
	int				i;
	t_stack_node	*new_node;
	t_stack_node	*head;
	t_stack_node	*current;

	if (!nmb || s != ' ')
		return (NULL);
	numbers = ft_split(nmb, s);
	if (!numbers)
		return (NULL);
	i = 0;
	head = NULL;
	current = NULL;
	while (numbers[i] != NULL)
	{
		new_node = (t_stack_node *)malloc(sizeof(t_stack_node) + 1);
		if (new_node == NULL)
			return (NULL);
		new_node->nbr = ft_atoi(numbers[i]);
		new_node->next = NULL;
		set_nodes(new_node, head, current);
		i++;
	}
	return (numbers);
}
