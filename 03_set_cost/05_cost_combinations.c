/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_cost_combinations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:45:33 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 12:37:23 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_ra_rb(t_node *target_node)
{
	if (target_node->ra <= target_node->rb)
	{
		target_node->rr = target_node->ra;
		target_node->rb -= target_node->ra;
		target_node->ra = 0;
		target_node->rra = 0;
		target_node->rrb = 0;
		target_node->rrr = 0;
	}
	else
	{
		target_node->rr = target_node->rb;
		target_node->ra -= target_node->rb;
		target_node->rb = 0;
		target_node->rra = 0;
		target_node->rrb = 0;
		target_node->rrr = 0;
	}
	target_node->cost = target_node->rr + target_node->ra + target_node->rb;
}

void	_ra_rrb(t_node *target_node)
{
	target_node->rb = 0;
	target_node->rr = 0;
	target_node->rra = 0;
	target_node->rrr = 0;
	target_node->cost = target_node->ra + target_node->rrb;
}

void	_rra_rb(t_node *target_node)
{
	target_node->ra = 0;
	target_node->rr = 0;
	target_node->rrb = 0;
	target_node->rrr = 0;
	target_node->cost = target_node->rra + target_node->rb;
}

void	_rra_rrb(t_node *target_node)
{
	if (target_node->rra <= target_node->rrb)
	{
		target_node->rrr = target_node->rra;
		target_node->rrb -= target_node->rra;
		target_node->ra = 0;
		target_node->rb = 0;
		target_node->rr = 0;
		target_node->rra = 0;
	}
	else
	{
		target_node->rrr = target_node->rrb;
		target_node->rra -= target_node->rrb;
		target_node->ra = 0;
		target_node->rb = 0;
		target_node->rr = 0;
		target_node->rrb = 0;
	}
	target_node->cost = target_node->rrr + target_node->rra + target_node->rrb;
}

int	_find_cheapest(int a, int b, int c, int d)
{
	int	min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	if (min > d)
		min = d;
	return (min);
}
