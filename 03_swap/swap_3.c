/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:30:31 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/18 14:48:22 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../header/push_swap.h"

void	_swap_3(t_node **stack)
{
	int	diff_value;

	diff_value = 0;
	if (((*stack)->nbr) > ((*stack)->next->nbr))
		diff_value += 1;
	if (((*stack)->nbr) > ((*stack)->prev->nbr))
		diff_value += 2;
	if (((*stack)->next->nbr) > ((*stack)->prev->nbr))
		diff_value += 4;
	printf("diff_value = %d\n", diff_value);
	_swap_3_execute(stack, diff_value);
	printf("swap_3 done\n");
	return ;
}
/*
1,2,3 = 0 -> NULL
2,1,3 = 1 -> sa
3,1,2 = 3 -> ra
1,3,2 = 4 -> sa, ra
2,3,1 = 6 -> rra
3,2,1 = 7 -> sa, rra
*/

void	_swap_3_execute(t_node **stack, int diff_value)
{
	if (diff_value == 1)
		_sa(stack, NULL, WRITE_OPR);
	else if (diff_value == 3)
		_ra(stack, NULL, WRITE_OPR);
	else if (diff_value == 4)
	{
		_sa(stack, NULL, WRITE_OPR);
		_ra(stack, NULL, WRITE_OPR);
	}
	else if (diff_value == 6)
		_rra(stack, NULL, WRITE_OPR);
	else if (diff_value == 7)
	{
		_sa(stack, NULL, WRITE_OPR);
		_rra(stack, NULL, WRITE_OPR);
	}
	return ;
}
