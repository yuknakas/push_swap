/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_set_big_stack_b .c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:57:23 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/04 15:35:24 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <stdio.h>

static int	_check_all_lis(t_node *stack_a)
{
	t_node	*start;

	start = stack_a;
	if (stack_a->correct_pos != 1)
		return (0);
	stack_a = stack_a->next;
	while (stack_a != start)
	{
		if (stack_a->correct_pos != 1)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static int	_check_present_section(t_node *target, t_node *stack_b)
{
	t_node	*first;

	if (target->section > _find_maximum(stack_b)->section)
		return (2);
	if (target->section < _find_minimum(stack_b)->section)
		return (3);
	first = stack_b;
	if (stack_b->section == target->section)
		return (1);
	stack_b = stack_b->next;
	while (stack_b != first)
	{
		if (stack_b->section == target->section)
			return (1);
		stack_b = stack_b->next;
	}
	return (0);
}

static void	_set_section_cost(t_node *target, t_node *stack_b)
{
	int	choice;

	if (stack_b == NULL)
	{
		target->rb = 0;
		target->rrb = 0;
		return ;
	}
	choice = _check_present_section(target, stack_b);
	if (choice == 1)
		_normal_section(target, stack_b);
	else if (choice == 2)
		_largest_section(target, stack_b);
	else if (choice == 3)
		_smallest_section(target, stack_b);
	else if (choice == 0)
		_new_section(target, stack_b);
}

static void	_set_big_b_cost(t_node *stack_a, t_node *stack_b)
{
	t_node	*current;

	_set_section_cost(stack_a, stack_b);
	current = stack_a->next;
	while (current != stack_a)
	{
		_set_section_cost(current, stack_b);
		current = current->next;
	}
}

void	_set_big_stack_b(t_node **stack_a, t_node **stack_b)
{
	while (_check_all_lis(*stack_a) != 1)
	{
		_set_self_cost_a(*stack_a);
		_set_big_b_cost(*stack_a, *stack_b);
		_add_cost(*stack_a);
		ps_execute_cheapest_node(stack_a, stack_b, 'a');
	}
}
