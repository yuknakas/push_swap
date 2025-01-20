/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:16:18 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/20 10:08:06 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	if (_preparation(argc, argv, &stack_a, &stack_b) != 0)
		return (1);
	_push_swap(&stack_a, &stack_b);
	_clean_up(stack_a);

}

//ccw ./srcs/* ./preparation/* ./swap/*.c ./swap/operations/*.c -L./libft -lft -o push_swap      