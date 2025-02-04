/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_target_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:42:09 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/04 11:04:45 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	_check_edge(t_node *stack_a, int target)
{
	if (_find_minimum(stack_a)->nbr > target)
		return (1);
	else if (_find_maximum(stack_a)->nbr < target)
		return (1);
	else
		return (0);
}

static void	_set_push_cost(t_node *stack_a, t_node *target)
{
	if (_check_edge(stack_a, target->nbr) == 1)
	{
		target->ra = 1;
		while (stack_a->nbr < stack_a->next->nbr)
		{
			target->ra++;
			stack_a = stack_a->next;
		}
		target->rra = ps_lstsize(stack_a) - target->ra;
	}
	else
	{
		target->ra = 1;
		while (1)
		{
			if (stack_a->nbr < target->nbr && target->nbr < stack_a->next->nbr)
				break ;
			target->ra++;
			stack_a = stack_a->next;
		}
		target->rra = ps_lstsize(stack_a) - target->ra;
	}
}

void	_set_target_cost_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*current;

	if (stack_b == NULL)
		return ;
	_set_push_cost(stack_a, stack_b);
	current = stack_b->next;
	while (current != stack_b)
	{
		_set_push_cost(stack_a, current);
		current = current->next;
	}
}
