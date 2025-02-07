/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:35:16 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/07 15:51:10 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	_checker(t_node *stack_a, t_node *stack_b)
{
	t_node	*tmp;

	if (stack_a == NULL || stack_b != NULL)
		return (1);
	tmp = stack_a;
	while (tmp != stack_a->prev)
	{
		if (tmp->nbr >= tmp->next->nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	_only_one_section(t_node *stack, int sec)
{
	t_node	*first;

	first = stack;
	if (stack->section != sec)
		return (1);
	stack = stack->next;
	while (stack != first)
	{
		if (stack->section != sec)
			return (1);
		stack = stack->next;
	}
	return (0);
}
