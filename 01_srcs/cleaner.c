/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:31:34 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/20 10:40:29 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <stdio.h>

void	_clean_up(t_node *stack_a)
{
	t_node	*tmp;
	t_node	*first;

	printf("---------- Final Result ----------\n");
	if (stack_a == NULL)
		return ;
	first = stack_a;
	while (stack_a->next != first)
	{
		tmp = stack_a->next;
		printf("%d\n", stack_a->nbr);
		free(stack_a);
		stack_a = tmp;
	}
	printf("%d\n", stack_a->nbr);
	free(stack_a);
}
