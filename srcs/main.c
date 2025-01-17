/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:16:18 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/17 15:35:03 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	// t_node	*tmp;

	stack_a = NULL;
	if (_preparation(argc, argv, &stack_a) != 0)
		return (1);
	_push_swap(&stack_a);
	final_results(stack_a);

	// while (stack_a != NULL)
	// {
	// 	tmp = stack_a->next;
	// 	printf("%d\n", stack_a->nbr);
	// 	free(stack_a);
	// 	stack_a = tmp;
	// }
	// stack_len = ft_lstsize(stack_a);
	// if (stack_len == 3)
	// 	_swap_3(&stack_a);
	// ft_lstclear(&stack_a, free);
	// return (0);
}

//ccw ./srcs/* ./make_stack/* -L./libft -lft -o outprogeam      