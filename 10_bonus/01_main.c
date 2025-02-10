/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:43:38 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/10 14:24:41 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

static void	_clean_all(t_node *stack_a, t_node *stack_b)
{
	_clean_up(stack_a);
	_clean_up(stack_b);
}

static void	_final_check(t_node *stack_a, t_node *stack_b)
{
	if (_checker(stack_a, stack_b) == 0)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*cmd;

	stack_a = NULL;
	if (ps_preparation(argc, argv, &stack_a, &stack_b) != 0)
		return (-1);
	cmd = get_next_line(STDIN_FILENO);
	while (cmd != NULL)
	{
		if (ps_exec_inputstr(&stack_a, &stack_b, cmd) == -1)
		{
			free(cmd);
			_clean_all(stack_a, stack_b);
			return (-1);
		}
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	_final_check(stack_a, stack_b);
	_clean_all(stack_a, stack_b);
	return (0);
}
