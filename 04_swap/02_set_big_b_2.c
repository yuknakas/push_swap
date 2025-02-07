/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_set_big_b_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:41:40 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/07 11:27:37 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	_normal_section(t_node *target, t_node *stack_b)
{
	int		aim_section;
	t_node	*last;

	aim_section = target->section;
	last = stack_b->prev;
	target->rb = 0;
	while (stack_b->section != aim_section)
	{
		target->rb++;
		stack_b = stack_b->next;
	}
	target->rrb = 0;
	while (last->section != aim_section)
	{
		target->rrb++;
		last = last->prev;
	}
}

static void	_largest_section(t_node *target, t_node *stack_b)
{
	t_node	*max_node;

	max_node = _find_maximum(stack_b);
	target->rb = 1;
	while (stack_b != max_node)
	{
		target->rb++;
		stack_b = stack_b->next;
	}
	target->rrb = ps_lstsize(stack_b) - target->rb;
}

static void	_smallest_section(t_node *target, t_node *stack_b)
{
	t_node	*min_node;

	min_node = _find_minimum(stack_b);
	target->rb = 1;
	while (stack_b != min_node)
	{
		target->rb++;
		stack_b = stack_b->next;
	}
	target->rrb = ps_lstsize(stack_b) - target->rb;
}

static void	_new_section(t_node *target, t_node *stack_b)
{
	target->rb = 1;
	while (1)
	{
		if (stack_b->section < target->section)
		{
			if (target->section < stack_b->next->section)
				break ;
		}
		target->rb++;
		stack_b = stack_b->next;
	}
	target->rrb = ps_lstsize(stack_b) - target->rb;
}

void	_set_section_cost(t_node *target, t_node *stack_b)
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
	else if (choice == 9)
		_largest_section(target, stack_b);
	else if (choice == -1)
		_smallest_section(target, stack_b);
	else if (choice == 0)
		_new_section(target, stack_b);
}
