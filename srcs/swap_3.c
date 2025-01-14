/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:30:31 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/14 12:08:59 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	_swap_3(t_node **stack_a)
{
	int	diff_value;

	diff_value = 0;
	if (((*stack_a)->nbr) > ((*stack_a)->next->nbr))
		diff_value += 1;
	if (((*stack_a)->nbr) > ((*stack_a)->next->next->nbr))
		diff_value += 2;
	if (((*stack_a)->next->nbr) > ((*stack_a)->next->next->nbr))
		diff_value += 4;
	_swap_3_execute(stack_a, diff_value);
	return ;
}
/*
1,2,3 = 0 -> NULL
2,1,3 = 1 -> sa
3,1,2 = 3 -> ra
1,3,2 = 5 -> sa, ra
2,3,1 = 6 -> rra
3,2,1 = 7 -> sa, rra
*/

void	_swap_3_execute(t_node **stack_a, int diff_value)
{
	if (diff_value == 1)
		_sa(stack_a, NULL, WRITE_OPR);
	else if (diff_value == 3)
		_ra(stack_a, NULL, WRITE_OPR);
	else if (diff_value == 5)
	{
		_sa(stack_a, NULL, WRITE_OPR);
		_ra(stack_a, NULL, WRITE_OPR);
	}
	else if (diff_value == 6)
		_rra(stack_a, NULL, WRITE_OPR);
	else if (diff_value == 7)
	{
		_sa(stack_a, NULL, WRITE_OPR);
		_rra(stack_a, NULL, WRITE_OPR);
	}
	return ;
}
