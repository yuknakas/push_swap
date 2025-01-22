/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:54:02 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/22 15:49:23 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	_swap_100(t_node **stack_a, t_node **stack_b)
{
	int	target;

	target = (_find_minimum(stack_a)->nbr + _find_maximum(stack_a)->nbr) / 2;
}
