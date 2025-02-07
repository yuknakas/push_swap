/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:16:18 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/07 10:11:31 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	if (ps_preparation(argc, argv, &stack_a, &stack_b) != 0)
		return (1);
	ps_push_swap(&stack_a, &stack_b);
	_clean_up(stack_a);
}
