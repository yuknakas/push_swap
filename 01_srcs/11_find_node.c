/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_find_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:55:45 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 14:55:55 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
