/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_self_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:48:49 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/04 15:34:04 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	_set_self_cost(t_node *stack_b)
{
	int	len_stack_b;
	int	i;

	if (stack_b == NULL)
		return ;
	len_stack_b = ps_lstsize(stack_b);
	i = 0;
	while (i < len_stack_b)
	{
		stack_b->rb = i;
		stack_b->rrb = len_stack_b - i;
		stack_b = stack_b->next;
		i++;
	}
}

void	ps_set_cost(t_node *stack_a, t_node *stack_b)
{
	_set_self_cost(stack_b);
	_set_target_cost_b(stack_a, stack_b);
	_add_cost(stack_b);
}
