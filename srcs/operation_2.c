/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:56:16 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/17 11:01:56 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_ra(t_node **stack_a, t_node **stack_b, int put_opr)
{
	t_node	*a2;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	a2 = (*stack_a)->next;
	(*stack_a)->next = NULL;
	ps_lstadd_back(&a2, *stack_a);
	*stack_a = a2;
	if (put_opr == WRITE_OPR)
		write(1, "ra\n", 3);
	stack_b = UNUSED;
}

void	_rb(t_node **stack_a, t_node **stack_b, int put_opr)
{
	t_node	*b2;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	b2 = (*stack_b)->next;
	(*stack_b)->next = NULL;
	ps_lstadd_back(&b2, *stack_b);
	*stack_b = b2;
	if (put_opr == WRITE_OPR)
		write(1, "rb\n", 3);
	stack_a = UNUSED;
}

void	_rr(t_node **stack_a, t_node **stack_b, int put_opr)
{
	_ra(stack_a, stack_b, NO_OPR);
	_rb(stack_a, stack_b, NO_OPR);
	write(1, "rr\n", 3);
	put_opr = UNUSED;
}
