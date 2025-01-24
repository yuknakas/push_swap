/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_self_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:48:49 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 15:15:24 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	_set_self_cost(t_node *stack_a, t_node *stack_b)
{
	int	len_stack;
	int	i;

	len_stack = ps_lstsize(stack_a);
	i = 0;
	while (i < len_stack)
	{
		stack_a->rra = i;
		stack_a->ra = len_stack - i;
		stack_a = stack_a->next;
		i++;
	}
	if (stack_b == NULL)
		return ;
	len_stack = ps_lstsize(stack_b);
	i = 0;
	while (i < len_stack)
	{
		stack_b->rrb = i;
		stack_b->rb = len_stack - i;
		stack_b = stack_b->next;
		i++;
	}
}

void	ps_set_cost(t_node *stack_a, t_node *stack_b, int target)
{
	_set_self_cost(stack_a, stack_b);
	_set_target_cost_a(stack_a, stack_b, target);
	_set_target_cost_b(stack_a, stack_b);
	_add_cost(stack_a, stack_b);
}
