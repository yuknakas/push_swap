/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_add_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:29:34 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/07 10:31:04 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	_set_cheapest(t_node *target_node)
{
	int	cost_ra_rb;
	int	cost_ra_rrb;
	int	cost_rra_rb;
	int	cost_rra_rrb;
	int	min;

	cost_ra_rb = target_node->ra;
	if (target_node->ra <= target_node->rb)
		cost_ra_rb = target_node->rb;
	cost_ra_rrb = target_node->ra + target_node->rrb;
	cost_rra_rb = target_node->rra + target_node->rb;
	cost_rra_rrb = target_node->rra;
	if (target_node->rra <= target_node->rrb)
		cost_rra_rrb = target_node->rrb;
	min = _find_cheapest(cost_ra_rb, cost_ra_rrb, cost_rra_rb, cost_rra_rrb);
	if (cost_ra_rb == min)
		_ra_rb(target_node);
	else if (cost_ra_rrb == min)
		_ra_rrb(target_node);
	else if (cost_rra_rb == min)
		_rra_rb(target_node);
	else
		_rra_rrb(target_node);
}

void	_add_cost(t_node *stack)
{
	t_node	*current;

	if (stack == NULL)
		return ;
	_set_cheapest(stack);
	current = stack->next;
	while (current != stack)
	{
		_set_cheapest(current);
		current = current->next;
	}
}
