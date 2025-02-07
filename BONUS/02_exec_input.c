/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_exec_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:53:51 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/07 17:00:58 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

int	ps_exec_input(t_node **stack_a, t_node **stack_b, char *cmd)
{
	if (cmd[0] == 's')
	{
		if (cmd[1] == "a" && cmd[2] == '\0')
			return (_sa(stack_a, stack_b, NO_OPR));
		if (cmd[1] == 'b' && cmd[2] == '\0')
			return (_sb(stack_a, stack_b, NO_OPR));
		if (cmd[1] == 's' && cmd[2] == '\0')
			return (_ss(stack_a, stack_b, NO_OPR));
		return (-1)
	}
}
