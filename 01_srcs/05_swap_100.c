/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_swap_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:54:02 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/07 10:12:19 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_swap_100(t_node **stack_a, t_node **stack_b)
{
	int	target;

	target = (_find_minimum(*stack_a)->nbr + _find_maximum(*stack_a)->nbr) / 2;
	_set_stack_b(stack_a, stack_b, target);
	while (_checker(_find_minimum(*stack_a), *stack_b) != 0)
	{
		ps_set_cost(*stack_a, *stack_b);
		ps_execute_cheapest_node(stack_a, stack_b, 'b');
	}
	_fix_top(stack_a);
}
