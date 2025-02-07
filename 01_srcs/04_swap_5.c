/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_swap_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:07:25 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/07 11:02:43 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	_checker_5(t_node *stack_a)
{
	t_node	*first;

	if (stack_a->correct_pos != 1)
		return (1);
	first = stack_a;
	stack_a = stack_a->next;
	while (stack_a != first)
	{
		if (stack_a->correct_pos != 1)
			return (1);
	}
	return (0);
}

static void	_stack_b_5(t_node **stack_a, t_node **stack_b, int *stack_len)
{
	t_node	*first;
	int		i;

	_longest_increacing_subseq(*stack_a, *stack_len);
	i = 0;
	(*stack_a)->correct_pos = i;
	i++;
	if ((*stack_a)->correct_pos == 1)
		(*stack_a)->cost = INT_MAX;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	while (*stack_a != first)
	{
		(*stack_a)->correct_pos = i;
		i++;
		if ((*stack_a)->correct_pos == 1)
			(*stack_a)->cost = INT_MAX;
		*stack_a = (*stack_a)->next;
	}
	while (*stack_len > 3 && _checker_5(*stack_a) != 0)
	{
		ps_execute_cheapest_node(stack_a, stack_b, 'a');
		(*stack_len)--;
	}
}

void	_swap_5(t_node **stack_a, t_node **stack_b, int stack_len)
{
	_stack_b_5(stack_a, stack_b, &stack_len);
	if (stack_len == 3)
		_swap_3(stack_a);
	while (_checker(_find_minimum(*stack_a), *stack_b) != 0)
	{
		ps_set_cost(*stack_a, *stack_b);
		ps_execute_cheapest_node(stack_a, stack_b, 'b');
	}
	_fix_top(stack_a);
}
