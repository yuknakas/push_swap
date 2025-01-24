/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greatest_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:31:42 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/22 15:27:30 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../header/push_swap.h"

static void	_lis_set_pos(t_node *last_node)
{
	while (last_node != NULL)
	{
		last_node->correct_pos = 1;
		last_node = last_node->lis_prev;
	}
}

t_node	*_find_node(t_node *first, int target)
{
	t_node	*current;

	if (first->nbr == target)
		return (first);
	current = first->next;
	while (current != first)
	{
		if (current->nbr == target)
			return (current);
		current = current->next;
	}
	return (NULL);
}

static void	_lis_cin(int *length, int *arr, t_node *current, t_node *stack)
{
	int	i;

	i = 0;
	while (i < *length)
	{
		if (current->nbr < arr[i])
		{
			arr[i] = current->nbr;
			if (i > 0)
				current->lis_prev = _find_node(stack, arr[i - 1]);
			return ;
		}
		i++;
	}
	if (i == *length && current->nbr > arr[*length - 1])
	{
		arr[*length] = current->nbr;
		current->lis_prev = _find_node(stack, arr[*length - 1]);
		(*length)++;
	}
	return ;
}

void	_longest_increacing_subseq(t_node *stack_a, size_t stack_size)
{
	int		*lis_arr;
	int		length;
	t_node	*current;
	t_node	*min;

	lis_arr = malloc(stack_size * sizeof(int));
	if (lis_arr == NULL)
		return ;
	lis_arr[0] = stack_a->nbr;
	current = stack_a->next;
	length = 1;
	while (current != stack_a)
	{
		_lis_cin(&length, lis_arr, current, stack_a);
		current = current->next;
	}
	_lis_set_pos(_find_node(stack_a, lis_arr[length - 1]));
	free(lis_arr);
}
