/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:46:32 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/17 16:41:05 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	_sa(t_node **stack_a, t_node **stack_b, int put_opr)
{
	int	tmp_value_a1;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (0);
	tmp_value_a1 = (*stack_a)->nbr;
	(*stack_a)->nbr = (*stack_a)->next->nbr;
	(*stack_a)->next->nbr = tmp_value_a1;
	if (put_opr == WRITE_OPR)
		write(1, "sa\n", 3);
	stack_b = UNUSED;
	return (1);
}

int	_sb(t_node **stack_a, t_node **stack_b, int put_opr)
{
	int	tmp_value_b1;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return (0);
	tmp_value_b1 = (*stack_b)->nbr;
	(*stack_b)->nbr = (*stack_b)->next->nbr;
	(*stack_b)->next->nbr = tmp_value_b1;
	if (put_opr == WRITE_OPR)
		write(1, "sb\n", 3);
	stack_a = UNUSED;
	return (1);
}

int	_ss(t_node **stack_a, t_node **stack_b, int put_opr)
{
	_sa(stack_a, stack_b, NO_OPR);
	_sb(stack_a, stack_b, NO_OPR);
	write(1, "ss\n", 3);
	put_opr = UNUSED;
	return (1);
}

int	_pa(t_node **stack_a, t_node **stack_b, int put_opr)
{
	t_node	*addr_b2;

	if (*stack_b == NULL)
		return (0);
	addr_b2 = (*stack_b)->next;
	ps_lstadd_front(stack_a, *stack_b);
	*stack_b = addr_b2;
	if (put_opr == WRITE_OPR)
		write(1, "pa\n", 3);
	return (1);
}

int	_pb(t_node **stack_a, t_node **stack_b, int put_opr)
{
	t_node	*addr_a2;

	if (*stack_a == NULL)
		return (0);
	addr_a2 = (*stack_a)->next;
	ps_lstadd_front(stack_b, *stack_a);
	*stack_a = addr_a2;
	if (put_opr == WRITE_OPR)
		write(1, "pb\n", 3);
	return (1);
}
