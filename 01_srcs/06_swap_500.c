/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_swap_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:35:27 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/07 11:43:22 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	_set_sec_array(int *sections, t_node *max_node, t_node *min_node)
{
	int	sixth;
	int	i;

	sixth = ((max_node->nbr / 6) - (min_node->nbr / 6));
	i = 0;
	while (i < 5)
	{
		sections[i] = min_node->nbr + sixth * (i + 1);
		i++;
	}
}

static void	_applicable_section(t_node *target, int *sections)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (target->nbr < sections[i])
		{
			target->section = 1;
			return ;
		}
		i++;
	}
	if (target->nbr > sections[4])
		target->section = 1;
}

static void	_set_section(int *sections, t_node *stack_a)
{
	t_node	*current;

	_applicable_section(stack_a, sections);
	current = stack_a->next;
	while (current != stack_a)
	{
		_applicable_section(current, sections);
		current = current->next;
	}
}

void	_swap_500(t_node **stack_a, t_node **stack_b)
{
	int	sections[5];

	_set_sec_array(sections, _find_maximum(*stack_a), _find_minimum(*stack_a));
	_set_section(sections, *stack_a);
	_set_big_stack_b(stack_a, stack_b);
	while (_checker(_find_minimum(*stack_a), *stack_b) != 0)
	{
		ps_set_cost(*stack_a, *stack_b);
		ps_execute_cheapest_node(stack_a, stack_b, 'b');
	}
	_fix_top(stack_a);
}
