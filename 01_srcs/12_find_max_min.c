/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_find_max_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:11:20 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 15:11:25 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_node	*_find_minimum(t_node *first)
{
	t_node	*current;
	int		min;

	min = first->nbr;
	current = first->next;
	while (current != first)
	{
		if (current->nbr < min)
			min = current->nbr;
		current = current->next;
	}
	return (_find_node(first, min));
}

t_node	*_find_maximum(t_node *first)
{
	t_node	*current;
	int		max;

	max = first->nbr;
	current = first->next;
	while (current != first)
	{
		if (current->nbr > max)
			max = current->nbr;
		current = current->next;
	}
	return (_find_node(first, max));
}
