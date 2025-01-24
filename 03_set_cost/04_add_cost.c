/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_add_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:29:34 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 15:53:57 by yuknakas         ###   ########.fr       */
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

static void	_add_cost_a(t_node *target)
{
	if (target->correct_pos == 1)
		target->cost = INT_MAX;
	else
		_set_cheapest(target);
}

void	_add_cost(t_node *stack_a, t_node *stack_b)
{
	t_node	*current;

	_add_cost_a(stack_a);
	current = stack_a->next;
	while (current != stack_a)
	{
		_add_cost_a(current);
		current = current->next;
	}
	if (stack_b == NULL)
		return ;
	_set_cheapest(stack_b);
	current = stack_b->next;
	while (current != stack_b)
	{
		_set_cheapest(current);
		current = current->next;
	}
}
