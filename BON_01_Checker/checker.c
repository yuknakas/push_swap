/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:35:16 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 15:54:41 by yuknakas         ###   ########.fr       */
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
