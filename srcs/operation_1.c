/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:46:32 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/14 12:08:07 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	_sa(t_node **stack_a, t_node **stack_b, int put_opr)
{
	int	tmp_value_a1;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp_value_a1 = (*stack_a)->nbr;
	(*stack_a)->nbr = (*stack_a)->next->nbr;
	(*stack_a)->next->nbr = tmp_value_a1;
	if (put_opr == WRITE_OPR)
		write(1, "sa\n", 3);
	stack_b = UNUSED;
}

void	_sb(t_node **stack_a, t_node **stack_b, int put_opr)
{
	int	tmp_value_b1;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp_value_b1 = (*stack_b)->nbr;
	(*stack_b)->nbr = (*stack_b)->next->nbr;
	(*stack_b)->next->nbr = tmp_value_b1;
	if (put_opr == WRITE_OPR)
		write(1, "sb\n", 3);
	stack_a = UNUSED;
}

void	_ss(t_node **stack_a, t_node **stack_b, int put_opr)
{
	_sa(stack_a, stack_b, NO_OPR);
	_sb(stack_a, stack_b, NO_OPR);
	write(1, "ss\n", 3);
	put_opr = UNUSED;
}

void	_pa(t_node **stack_a, t_node **stack_b, int put_opr)
{
	t_node	*addr_b2;

	if (*stack_b == NULL)
		return ;
	addr_b2 = (*stack_b)->next;
	ps_lstadd_front(stack_a, *stack_b);
	*stack_b = addr_b2;
	if (put_opr == WRITE_OPR)
		write(1, "pa\n", 3);
}

void	_pb(t_node **stack_a, t_node **stack_b, int put_opr)
{
	t_node	*addr_a2;

	if (*stack_a == NULL)
		return ;
	addr_a2 = (*stack_a)->next;
	ps_lstadd_front(stack_b, *stack_a);
	*stack_a = addr_a2;
	if (put_opr == WRITE_OPR)
		write(1, "pb\n", 3);
}
