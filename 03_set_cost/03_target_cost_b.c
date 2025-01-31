/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_target_cost_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:51:29 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/31 15:37:28 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <stdio.h>

static t_node	*_next_set(t_node *first)
{
	t_node	*current;

	current = first->next;
	while (current->correct_pos != 1)
		current = current->next;
	return (current);
}

static int	_check_if_edge(t_node *start_a, t_node *low, t_node *high)
{
	while (low != high)
	{
		if (low == start_a)
			return (1);
		low = low->next;
	}
	return (0);
}

static void	_set_edge(t_node *start_a, t_node *low, t_node *high, t_node *aim)
{
	t_node	*tmp;

	printf("low = %d. high = %d\n", low->nbr, high->nbr);
	if (_check_if_edge(start_a, low, high) == 1)
	{
		aim->ra = 0;
		aim->rra = 0;
		return ;
	}
	tmp = start_a;
	aim->ra = 1;
	while (start_a != low)
	{
		aim->ra++;
		start_a = start_a->next;
	}
	aim->rra = 0;
	while (tmp != high)
	{
		aim->rra++;
		tmp = tmp->prev;
	}
	return ;
}

static void	_set_push_back_cost(t_node *stack_a, t_node *target_node)
{
	int		cost;
	int		target;
	t_node	*set_node;
	t_node	*first_set;

	first_set = _next_set(stack_a->prev);
	set_node = _next_set(first_set);
	target = target_node->nbr;
	if (first_set->nbr < target && set_node->nbr > target)
		return (_set_edge(stack_a, set_node, _next_set(set_node), target_node));
	while (set_node != first_set)
	{
		if (set_node->nbr < target && (_next_set(set_node))->nbr > target)
		{
			_set_edge(stack_a, set_node, _next_set(set_node), target_node);
			return ;
		}
		set_node = _next_set(set_node);
	}
	while (set_node->nbr < _next_set(set_node)->nbr)
		set_node = _next_set(set_node);
	return (_set_edge(stack_a, set_node, _next_set(set_node), target_node));
}

void	_set_target_cost_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*current;

	if (stack_b == NULL)
		return ;
	_set_push_back_cost(stack_a, stack_b);
	current = stack_b->next;
	while (current != stack_b)
	{
		_set_push_back_cost(stack_a, current);
		current = current->next;
	}
}
