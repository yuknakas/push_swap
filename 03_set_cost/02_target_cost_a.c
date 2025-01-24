/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_target_cost_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:06:36 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 16:50:03 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	_find_aim_top(t_node *current, int target, t_node *stack_b, int len)
{
	int	count;

	count = 0;
	if (current->nbr < target)
	{
		while (stack_b->nbr > target && count < len)
		{
			count++;
			stack_b = stack_b->next;
		}
	}
	else
	{
		while (stack_b->nbr < target && count < len)
		{
			count++;
			stack_b = stack_b->next;
		}
	}
	if (count == len)
		count = 0;
	current->rrb = count;
}

static void	_find_aim_bot(t_node *current, int target, t_node *stack_b, int len)
{
	int	count;

	count = 0;
	if (current->nbr < target)
	{
		while (stack_b->nbr > target && count < len)
		{
			count++;
			stack_b = stack_b->prev;
		}
	}
	else
	{
		while (stack_b->nbr < target && count < len)
		{
			count++;
			stack_b = stack_b->prev;
		}
	}
	if (count == len)
		count = 0;
	current->rb = count;
}

static void	_a_cost_zero(t_node *stack_a)
{
	t_node	*current;

	stack_a->rb = 0;
	stack_a->rrb = 0;
	current = stack_a->next;
	while (current != stack_a)
	{
		current->rb = 0;
		current->rrb = 0;
		current = current->next;
	}
}

void	_set_target_cost_a(t_node *stack_a, t_node *stack_b, int target)
{
	t_node	*current;
	size_t	stack_len;

	if (stack_b == NULL)
		return (_a_cost_zero(stack_a));
	stack_len = ps_lstsize(stack_b);
	_find_aim_top(stack_a, target, stack_b, stack_len);
	_find_aim_bot(stack_a, target, stack_b, stack_len);
	current = stack_a->next;
	while (current != stack_a)
	{
		_find_aim_top(current, target, stack_b, stack_len);
		_find_aim_bot(current, target, stack_b, stack_len);
		current = current->next;
	}
}
