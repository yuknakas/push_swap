/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_execute_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:11:40 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/07 10:31:26 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_exc_min(t_node **stack_a, t_node **stack_b, t_node *min_node, char c)
{
	while (min_node->ra > 0)
		min_node->ra -= _ra(stack_a, stack_b, WRITE_OPR);
	while (min_node->rb > 0)
		min_node->rb -= _rb(stack_a, stack_b, WRITE_OPR);
	while (min_node->rr > 0)
		min_node->rr -= _rr(stack_a, stack_b, WRITE_OPR);
	while (min_node->rra > 0)
		min_node->rra -= _rra(stack_a, stack_b, WRITE_OPR);
	while (min_node->rrb > 0)
		min_node->rrb -= _rrb(stack_a, stack_b, WRITE_OPR);
	while (min_node->rrr > 0)
		min_node->rrr -= _rrr(stack_a, stack_b, WRITE_OPR);
	if (c == 'a')
	{
		_pb(stack_a, stack_b, WRITE_OPR);
	}
	if (c == 'b')
	{
		_pa(stack_a, stack_b, WRITE_OPR);
	}
}
