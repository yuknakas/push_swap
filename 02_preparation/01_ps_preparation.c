/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ps_preparation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:01:34 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 15:01:52 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ps_preparation(int argc, char **argv, t_node **stack_a, t_node **stack_b)
{
	if (argc < 2)
		return (1);
	if (argc == 2)
		*stack_a = _split_stack(argv[1]);
	else
		*stack_a = _make_stack((argc - 1), (argv + 1), NO_OPR);
	if (*stack_a == NULL)
		return (1);
	*stack_b = NULL;
	return (0);
}
