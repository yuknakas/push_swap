/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_top.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:46:27 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 14:47:24 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_fix_top(t_node **stack)
{
	int		cost;
	int		stack_len;
	t_node	*first;

	if (*stack == NULL)
		return ;
	cost = 1;
	first = *stack;
	stack_len = ps_lstsize(first);
	if (stack_len < 2)
		return ;
	while (first->nbr < first->next->nbr)
	{
		cost++;
		first = first->next;
	}
	if (cost * 2 < stack_len)
		while (cost > 0)
			cost -= _ra(stack, NULL, WRITE_OPR);
	else
		while (cost < stack_len)
			cost += _rra(stack, NULL, WRITE_OPR);
}
