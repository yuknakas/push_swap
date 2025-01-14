/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:16:18 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/14 16:34:19 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	*tmp;
	// int		stack_len;

	if (argc < 2)
		return (_p_error("1"));
	if (argc == 2)
		stack_a = _split_stack(argv[1]);
	else
		stack_a = _make_stack((argc - 1), (argv + 1), NO_OPR);
	if (stack_a == NULL)
		return (_p_error("Error when making stack\n"));

	while (*stack_a != NULL)
	{
		tmp = (*stack_a)->next;
		printf("%d\n", (*stack_a)->nbr);
		free(*stack_a);
		*stack_a = tmp;
	}
	free(stack_a);
	// stack_len = ft_lstsize(stack_a);
	// if (stack_len == 3)
	// 	_swap_3(&stack_a);
	// ft_lstclear(&stack_a, free);
	// return (0);
	return (0);
}

//ccw ./srcs/* ./make_stack/* -L./libft -lft -o outprogeam      