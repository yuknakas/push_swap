/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_set_big_b_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:41:40 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/07 16:36:52 by yuknakas         ###   ########.fr       */
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
	int		max_sec;

	max_sec = _find_maximum(stack_b)->section;
	if (_only_one_section(stack_b, max_sec) == 0)
	{
		target->rb = 0;
		target->rrb = 0;
		return ;
	}
	target->rrb = 0;
	stack_b = stack_b->prev;
	while (stack_b->section != max_sec)
	{
		target->rrb++;
		stack_b = stack_b->prev;
	}
	target->rb = ps_lstsize(stack_b) - target->rrb;
}

static void	_smallest_section(t_node *target, t_node *stack_b)
{
	int		min_sec;

	min_sec = _find_minimum(stack_b)->section;
	if (_only_one_section(stack_b, min_sec) == 0)
	{
		target->rb = 0;
		target->rrb = 0;
		return ;
	}
	target->rb = 0;
	while (stack_b->section != min_sec)
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
