/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:26:35 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/22 14:54:30 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../header/push_swap.h"

void	_push_swap(t_node **stack_a, t_node **stack_b)
{
	int	stack_len;

	stack_len = ps_lstsize(*stack_a);
	printf("stack_len = %d\n", stack_len);
	if (stack_len <= 2)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			_sa(stack_a, NULL, WRITE_OPR);
	}
	else if (stack_len == 3)
		_swap_3(stack_a);
	else if (stack_len <= 5)
		_swap_5(stack_a, stack_b, stack_len);
	else
		_push_swap_large(stack_a, stack_b, stack_len);
}

void	_push_swap_large(t_node **stack_a, t_node **stack_b, int stack_len)
{
	_longest_increacing_subseq(_find_minimum(*stack_a), stack_len);
	if (stack_len < 120)
		_swap_100
}
