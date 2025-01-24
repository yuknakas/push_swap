/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:07:25 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 14:46:07 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../header/push_swap.h"

int	_cost_target(t_node *first, int target)
{
	int		cost;
	t_node	*current;

	if (first->nbr > target && first->prev->nbr < target)
		return (0);
	cost = 1;
	current = first->next;
	while (current != first && current->nbr < target)
	{
		if (current->nbr < current->prev->nbr)
			return (cost);
		cost++;
		current = current->next;
	}
	return (cost);
}

static void	_push_back_5(t_node **stack_a, t_node **stack_b)
{
	int	cost;
	int	stack_len;

	printf("push_back enter\n");
	while (*stack_b != NULL)
	{
		stack_len = ps_lstsize(*stack_a);
		cost = _cost_target(*stack_a, (*stack_b)->nbr);
		printf("cost = %d\n", cost);
		if (cost * 2 < stack_len)
		{
			while (cost > 0)
				cost -= _ra(stack_a, NULL, WRITE_OPR);
		}
		else
		{
			while (cost < stack_len)
				cost += _rra(stack_a, NULL, WRITE_OPR);
		}
		_pa(stack_a, stack_b, WRITE_OPR);
	}
	printf("push_back exit\n");
}

void	_swap_5(t_node **stack_a, t_node **stack_b, int stack_len)
{
	while (stack_len > 3)
		stack_len -= _pb(stack_a, stack_b, WRITE_OPR);
	_swap_3(stack_a);
	_push_swap(stack_b, NULL);
	_push_back_5(stack_a, stack_b);
	_fix_top(stack_a);
}
