/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:27:26 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/17 11:01:56 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_rra(t_node **stack_a, t_node **stack_b, int put_opr)
{
	t_node	*a_last;

	if (*stack_a == NULL)
		return ;
	a_last = ps_lstlast(*stack_a);
	ps_lstadd_front(stack_a, a_last);
	a_last = ps_lstlast(*stack_a);
	a_last->next = NULL;
	if (put_opr == WRITE_OPR)
		write(1, "rra\n", 4);
	stack_b = UNUSED;
}

void	_rrb(t_node **stack_a, t_node **stack_b, int put_opr)
{
	t_node	*b_last;

	if (*stack_b == NULL)
		return ;
	b_last = ps_lstlast(*stack_b);
	ps_lstadd_front(stack_b, b_last);
	b_last = ps_lstlast(*stack_b);
	b_last->next = NULL;
	if (put_opr == WRITE_OPR)
		write(1, "rrb\n", 4);
	stack_a = UNUSED;
}

void	_rrr(t_node **stack_a, t_node **stack_b, int put_opr)
{
	_rra(stack_a, stack_b, NO_OPR);
	_rrb(stack_a, stack_b, NO_OPR);
	write(1, "rrr\n", 4);
	put_opr = UNUSED;
}
