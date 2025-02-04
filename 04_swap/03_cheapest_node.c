/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_cheapest_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:27:28 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/04 11:56:14 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static t_node	*_chose_min_a(t_node *stack_a)
{
	t_node	*min_a;
	t_node	*current;

	min_a = stack_a;
	if (min_a->correct_pos == 1)
		min_a->cost = INT_MAX;
	current = stack_a->next;
	while (current != stack_a)
	{
		if (min_a->cost > current->cost && current->correct_pos != 1)
			min_a = current;
		current = current->next;
	}
	if (min_a->correct_pos == 1)
		return (NULL);
	return (min_a);
}

static t_node	*_chose_min_b(t_node *stack_b)
{
	t_node	*min_b;
	t_node	*current;

	if (stack_b == NULL)
		return (NULL);
	min_b = stack_b;
	current = stack_b->next;
	while (current != stack_b)
	{
		if (min_b->cost > current->cost)
			min_b = current;
		current = current->next;
	}
	return (min_b);
}

void	ps_execute_cheapest_node(t_node **stack_a, t_node **stack_b, char c)
{
	t_node	*min;

	if (c == 'a')
		min = _chose_min_a(*stack_a);
	else if (c == 'b')
		min = _chose_min_b(*stack_b);
	if (min == NULL)
		return ;
	if (c == 'a')
		_exc_min(stack_a, stack_b, min, 'a');
	else if (c == 'b')
		_exc_min(stack_a, stack_b, min, 'b');
}
