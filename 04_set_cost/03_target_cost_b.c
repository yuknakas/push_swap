/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:51:29 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 11:28:05 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_node	*_next_set(t_node *first)
{
	t_node	*current;

	current = first->next;
	while (current->correct_pos != 1)
		current = current->next;
	return (current);
}

void	_set_edge(t_node *start_a, t_node *low, t_node *high, t_node *target)
{
	while (low != start_a)
	{
		if (low == high)
		{
			target->rra = 0;
			while (start_a != low)
			{
				target->rra++;
				start_a = start_a->next;
			}
			target->ra = 0;
			while (start_a != high)
			{
				target->ra++;
				start_a = start_a->prev;
			}
			return ;
		}
		low = low->next;
	}
	target->ra = 0;
	target->rra = 0;
}

void	_set_push_back_cost(t_node *stack_a, t_node *target_node)
{
	int		cost;
	int		target;
	t_node	*set_node;

	set_node = _find_next_set_node(stack_a->prev);
	target = target_node->nbr;
	while (set_node->nbr < _next_set(set_node)->nbr)
	{
		if (set_node->nbr < target && (_next_set(set_node))->nbr > target)
			break ;
		set_node = _next_set(set_node);
	}
	_set_edge(stack_a, set_node, _next_set(set_node), target_node);
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
		_set_oush_back_cost(stack_a, current);
		current == current->next;
	}
}
