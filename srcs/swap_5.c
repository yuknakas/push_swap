/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:07:25 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/17 16:57:33 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../header/push_swap.h"

void	_swap_5(t_node **stack_a, t_node **stack_b, int stack_len)
{
	int	rot_nbr;

	while (stack_len > 3)
	{
		_pb(stack_a, stack_b, WRITE_OPR);
		stack_len--;
	}
	_swap_3(stack_a);
	rot_nbr = 0;
	if ((*stack_b)->nbr > (*stack_b)->next->nbr)
	{
		if ((*stack_b)->next != NULL && (*stack_a)->nbr < (*stack_b)->next->nbr)
			rot_nbr += _ss(stack_a, NULL, WRITE_OPR);
		else
			_sb(NULL, stack_b, WRITE_OPR);
	}
	while (*stack_b != NULL)
	{
		while ((*stack_a)->nbr < (*stack_b)->nbr)
			rot_nbr += _ra(stack_a, NULL, WRITE_OPR);
		rot_nbr -= _pa(stack_a, stack_b, WRITE_OPR);
	}
	while (rot_nbr > 0)
		rot_nbr -= _rra(stack_a, NULL, WRITE_OPR);
}
