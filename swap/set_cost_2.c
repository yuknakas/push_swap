/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:06:36 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/22 16:30:12 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_find_target_top(t_node *stack_a, int target, t_node *stack_b)
{
	int	count;

	count = 0;
	if (stack_a->nbr < target)
	{
		while (stack_b->nbr > target)
		{
			count++;
			stack_b = stack_b->next;
		}
	}
	else
	{
		while (stack_b->nbr < target)
		{
			count++;
			stack_b = stack_b->next;
		}
	}
	stack_a->rrb = count;
}

void	_find_target_bottom(t_node *stack_a, int target, t_node *stack_b)
{
	int	count;

	count = 0;
	if (stack_a->nbr < target)
	{
		while (stack_b->nbr > target)
		{
			count++;
			stack_b = stack_b->prev;
		}
	}
	else
	{
		while (stack_b->nbr < target)
		{
			count++;
			stack_b = stack_b->prev;
		}
	}
	stack_a->rb = count;
}

void	_set_target_cost(t_node *stack_a, t_node *stack_b, int target)
{
	t_node	*current;

	_find_target_top(stack_a, target, stack_b);
	_find_target_bottom(stack_a, target, stack_b);
	current = stack_a->next;
	while (current != stack_a)
	{
		_find_target_top(current, target, stack_b);
		_find_target_bottom(current, target, stack_b);
		current = current->next;
	}
}

static t_node	*_next_set(t_node *first)
{
	t_node	*current;

	current = first->next;
	while (current->correct_pos != 1)
		current = current->next;
	return (current);
}

void	_set_push_back_cost(t_node *stack_a, t_node *stack_b)
{
	int		cost;
	int		target;
	t_node	*set_node;

	set_node = _find_next_set_node(stack_a->prev);
	target = stack_b->nbr;
	while (set_node->nbr < _next_set(set_node)->nbr)
	{
		if (set_node->nbr < target && (_next_set(set_node))->nbr > target)
			break ;
		set_node = _next_set(set_node);
	}
	cost = 1;
	while (stack_a->nbr < target)
	{
		if (stack_a->nbr < stack_a->prev->nbr)
			return (cost);
		cost++;
		stack_a = stack_a->next;
	}
	return (cost);
}
