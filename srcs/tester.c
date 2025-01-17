/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:31:34 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/17 15:35:31 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <stdio.h>

void	final_results(t_node *stack_a)
{
	t_node	*tmp;

	while (stack_a != NULL)
	{
		tmp = stack_a->next;
		printf("%d\n", stack_a->nbr);
		free(stack_a);
		stack_a = tmp;
	}
}
