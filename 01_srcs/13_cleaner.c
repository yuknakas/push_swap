/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:31:34 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/07 10:12:34 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_clean_up(t_node *stack_a)
{
	t_node	*tmp;
	t_node	*first;

	if (stack_a == NULL)
		return ;
	first = stack_a;
	while (stack_a->next != first)
	{
		tmp = stack_a->next;
		free(stack_a);
		stack_a = tmp;
	}
	free(stack_a);
}
