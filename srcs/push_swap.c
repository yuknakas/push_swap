/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:26:35 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/17 15:45:25 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../header/push_swap.h"

void	_push_swap(t_node **stack_a)
{
	int	stack_len;

	stack_len = ps_lstsize(*stack_a);
	if (stack_len == 2)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			_sa(stack_a, NULL, WRITE_OPR);
	}
	if (stack_len == 3)
		_swap_3(stack_a);
}
