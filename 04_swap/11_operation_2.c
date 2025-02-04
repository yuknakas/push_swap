/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_operation_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:56:16 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/04 09:20:44 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	_ra(t_node **stack_a, t_node **stack_b, int put_opr)
{
	t_node	*a2;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (0);
	*stack_a = (*stack_a)->next;
	if (put_opr == WRITE_OPR)
		write(1, "ra\n", 3);
	return (1);
}

int	_rb(t_node **stack_a, t_node **stack_b, int put_opr)
{
	t_node	*b2;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return (0);
	*stack_b = (*stack_b)->next;
	if (put_opr == WRITE_OPR)
		write(1, "rb\n", 3);
	stack_a = UNUSED;
	return (1);
}

int	_rr(t_node **stack_a, t_node **stack_b, int put_opr)
{
	_ra(stack_a, stack_b, NO_OPR);
	_rb(stack_a, stack_b, NO_OPR);
	write(1, "rr\n", 3);
	put_opr = UNUSED;
	return (1);
}
