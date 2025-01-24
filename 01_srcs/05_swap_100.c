/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_swap_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:54:02 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 16:53:16 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <stdio.h>

void	_swap_100(t_node **stack_a, t_node **stack_b)
{
	int	target;

	target = (_find_minimum(*stack_a)->nbr + _find_maximum(*stack_a)->nbr) / 2;
	while (_checker(_find_minimum(*stack_a), *stack_b) != 0)
	{
		ps_set_cost(*stack_a, *stack_b, target);
		ps_execute_cheapest_node(stack_a, stack_b);
	}
	printf("Stack A\n");
	_check_lis(*stack_a);
	printf("Stack B\n");
	_check_lis(*stack_b);
	_fix_top(stack_a);
}
