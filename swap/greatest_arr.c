/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greatest_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:31:42 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/20 15:50:12 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	_lis_init(t_node *stack, t_node **curr, t_node *arr, int *len)
{
	*curr = stack;
	arr = stack;
	*curr = (*curr)->next;
}

static void	_lis_set_pos(t_node *last_node)
{
	while (last_node != NULL)
	{
		last_node->correct_pos = 1;
		last_node = last_node->lis_prev;
	}
}

static int	_lis_clast(t_node **current, t_node **prev, int *arr, int *length)
{
	if (arr[*length - 1] < (*current)->nbr)
	{
		arr[*length] = (*current)->nbr;
		(*current)->lis_prev = prev;
		prev = *current;
		*length++;
		return (1);
	}
	return (0);
}

static void	_lis_cin(int length, int *arr, t_node *current)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (current->nbr < arr[length])
	}
}

void	_longest_increacing_subseq(t_node *stack_a, size_t stack_size)
{
	t_node	*lis_arr;
	int		length;
	t_node	*current;
	t_node	*tmp_lis_prev;

	lis_arr = malloc(stack_size * sizeof(t_node *));
	if (lis_arr == NULL)
		return ;
	_lis_init(stack_a, &current, &tmp_lis_prev, lis_arr);
	length = 1;
	while (current != stack_a)
	{
		if (_lis_clast(&current, &tmp_lis_prev, lis_arr, &length) == 0)
		
	}
	free(lis_arr);
}
