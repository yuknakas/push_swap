/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_operation_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:46:32 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 15:51:39 by yuknakas         ###   ########.fr       */
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
	t_node	*b_2;
	t_node	*b_last;

	if (stack_a == NULL || *stack_b == NULL)
		return (0);
	b_2 = (*stack_b)->next;
	b_last = (*stack_b)->prev;
	(*stack_b)->correct_pos = 1;
	ps_lstadd_front(stack_a, *stack_b);
	if (b_2 == *stack_b)
	{
		*stack_b = NULL;
		if (put_opr == WRITE_OPR)
			write(1, "pa\n", 3);
		return (1);
	}
	b_2->prev = b_last;
	b_last->next = b_2;
	*stack_b = b_2;
	if (put_opr == WRITE_OPR)
		write(1, "pa\n", 3);
	return (1);
}

int	_pb(t_node **stack_a, t_node **stack_b, int put_opr)
{
	t_node	*a_2;
	t_node	*a_last;

	if (*stack_a == NULL || stack_b == NULL)
		return (0);
	a_2 = (*stack_a)->next;
	a_last = (*stack_a)->prev;
	ps_lstadd_front(stack_b, *stack_a);
	if (a_2 == *stack_a)
	{
		*stack_a = NULL;
		if (put_opr == WRITE_OPR)
			write(1, "pb\n", 3);
		return (1);
	}
	a_2->prev = a_last;
	a_last->next = a_2;
	*stack_a = a_2;
	if (put_opr == WRITE_OPR)
		write(1, "pb\n", 3);
	return (1);
}
