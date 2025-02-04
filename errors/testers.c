/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:41:47 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/04 16:11:53 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../header/push_swap.h"

void	_check_lis(t_node *stack_a)
{
	t_node	*tmp;
	t_node	*first;

	printf("---------- Check LIS ----------\n");
	if (stack_a == NULL)
		return ;
	first = stack_a;
	while (stack_a->next != first)
	{
		tmp = stack_a->next;
		if (stack_a->correct_pos == 1)
			printf("LIS: ");
		printf("%d\n", stack_a->nbr);
		stack_a = tmp;
	}
	if (stack_a->correct_pos == 1)
		printf("LIS: ");
	printf("%d\n", stack_a->nbr);
	printf("-------------------------------\n");
}
