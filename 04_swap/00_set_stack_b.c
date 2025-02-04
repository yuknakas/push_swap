/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_stack_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:57:23 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/04 11:17:24 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	_decide_pile(t_node **stack_a, t_node **stack_b, int target)
{
	if (*stack_b == NULL)
	{
		_pb(stack_a, stack_b, WRITE_OPR);
		return ;
	}
	if ((*stack_a)->nbr < target)
	{
		_pb(stack_a, stack_b, WRITE_OPR);
		return ;
	}
	else
	{
		_pb(stack_a, stack_b, WRITE_OPR);
		_rb(stack_a, stack_b, WRITE_OPR);
		return ;
	}
}

static t_node	*_last_incorrect(t_node *stack_a)
{
	t_node	*last;

	last = stack_a->prev;
	stack_a = stack_a->prev;
	while (stack_a->prev != last)
	{
		if (stack_a->correct_pos != 1)
			return (stack_a);
		stack_a = stack_a->prev;
	}
	return (NULL);
}

void	_set_stack_b(t_node **stack_a, t_node **stack_b, int target)
{
	t_node	*last;

	last = _last_incorrect(*stack_a);
	if (last == NULL)
		return ;
	while (*stack_a != last)
	{
		if ((*stack_a)->correct_pos != 1)
			_decide_pile(stack_a, stack_b, target);
		else
			_ra(stack_a, stack_b, WRITE_OPR);
	}
	_decide_pile(stack_a, stack_b, target);
}
