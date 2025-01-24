/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:27:26 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/18 15:11:11 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	_rra(t_node **stack_a, t_node **stack_b, int put_opr)
{
	t_node	*a_last;
	t_node	*a_second_last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (0);
	*stack_a = (*stack_a)->prev;
	if (put_opr == WRITE_OPR)
		write(1, "rra\n", 4);
	stack_b = UNUSED;
	return (1);
}

int	_rrb(t_node **stack_a, t_node **stack_b, int put_opr)
{
	t_node	*b_last;
	t_node	*b_second_last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return (0);
	*stack_b = (*stack_b)->prev;
	if (put_opr == WRITE_OPR)
		write(1, "rrb\n", 4);
	stack_a = UNUSED;
	return (1);
}

int	_rrr(t_node **stack_a, t_node **stack_b, int put_opr)
{
	_rra(stack_a, stack_b, NO_OPR);
	_rrb(stack_a, stack_b, NO_OPR);
	write(1, "rrr\n", 4);
	put_opr = UNUSED;
	return (1);
}
