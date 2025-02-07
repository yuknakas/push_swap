/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_greatest_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:31:42 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/07 10:12:21 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	_lis_set_pos(t_node *last_node)
{
	while (last_node != NULL)
	{
		last_node->correct_pos = 1;
		last_node = last_node->lis_prev;
	}
}

static void	_lis_cin(int *length, t_node **arr, t_node *current)
{
	int	i;

	i = 0;
	while (i < *length)
	{
		if (current->nbr < arr[i]->nbr)
		{
			arr[i] = current;
			if (i > 0)
				current->lis_prev = arr[i - 1];
			return ;
		}
		i++;
	}
	if (i == *length)
	{
		arr[*length] = current;
		current->lis_prev = arr[*length - 1];
		(*length)++;
	}
}

static void	_init_pos(t_node *stack_a)
{
	t_node	*current;

	stack_a->correct_pos = -1;
	stack_a->lis_prev = NULL;
	current = stack_a->next;
	while (current != stack_a)
	{
		current->correct_pos = -1;
		current->lis_prev = NULL;
		current = current->next;
	}
}

static int	_lis_node(t_node *first, size_t stack_size)
{
	t_node	**lis_arr;
	int		length;
	t_node	*current;

	lis_arr = malloc(stack_size * sizeof(t_node *));
	if (lis_arr == NULL)
		return (-1);
	lis_arr[0] = first;
	current = first->next;
	length = 1;
	_init_pos(first);
	while (current != first)
	{
		_lis_cin(&length, lis_arr, current);
		current = current->next;
	}
	_lis_set_pos(lis_arr[length - 1]);
	free(lis_arr);
	return (length);
}

void	_longest_increacing_subseq(t_node *stack_a, size_t stack_size)
{
	int		max;
	int		tmp;
	t_node	*current;
	t_node	*first;

	max = _lis_node(stack_a, stack_size);
	first = stack_a;
	current = stack_a->next;
	while (current != stack_a)
	{
		tmp = _lis_node(current, stack_size);
		if (tmp != -1 && max < tmp)
		{
			max = tmp;
			first = current;
		}
		current = current->next;
	}
	_lis_node(first, stack_size);
}
