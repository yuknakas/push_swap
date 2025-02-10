/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:31:34 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/10 10:46:00 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_clean_up(t_node *stack)
{
	t_node	*tmp;
	t_node	*first;

	if (stack == NULL)
		return ;
	first = stack;
	while (stack->next != first)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	free(stack);
}
