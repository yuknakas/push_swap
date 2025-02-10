/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_exec_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:53:51 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/10 14:40:44 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

static int	_char_to_cmd_2(char *cmd)
{
	if (cmd[0] != 'r')
		return (ERR_CMD);
	if (cmd[1] == 'a' && cmd[2] == '\0')
		return (CMD_RA);
	if (cmd[1] == 'b' && cmd[2] == '\0')
		return (CMD_RB);
	if (cmd[1] == 'r')
	{
		if (cmd[2] == '\0')
			return (CMD_RR);
		if (cmd[2] == 'a' && cmd[3] == '\0')
			return (CMD_RRA);
		if (cmd[2] == 'b' && cmd[3] == '\0')
			return (CMD_RRB);
		if (cmd[2] == 'r' && cmd[3] == '\0')
			return (CMD_RRR);
	}
	return (ERR_CMD);
}

static int	_char_to_cmd(char *cmd)
{
	if (cmd[0] == 's')
	{
		if (cmd[1] == 'a' && cmd[2] == '\0')
			return (CMD_SA);
		if (cmd[1] == 'b' && cmd[2] == '\0')
			return (CMD_SB);
		if (cmd[1] == 's' && cmd[2] == '\0')
			return (CMD_SS);
		return (ERR_CMD);
	}
	if (cmd[0] == 'p')
	{
		if (cmd[1] == 'a' && cmd[2] == '\0')
			return (CMD_PA);
		if (cmd[1] == 'b' && cmd[2] == '\0')
			return (CMD_PB);
		return (ERR_CMD);
	}
	return (_char_to_cmd_2(cmd));
}

static int	_exec_cmd(t_node **stack_a, t_node **stack_b, int nbr_cmd)
{
	if (nbr_cmd == CMD_SA)
		return (_sa(stack_a, stack_b, NO_OPR));
	if (nbr_cmd == CMD_SB)
		return (_sb(stack_a, stack_b, NO_OPR));
	if (nbr_cmd == CMD_SS)
		return (_ss(stack_a, stack_b, NO_OPR));
	if (nbr_cmd == CMD_PA)
		return (_pa(stack_a, stack_b, NO_OPR));
	if (nbr_cmd == CMD_PB)
		return (_pb(stack_a, stack_b, NO_OPR));
	if (nbr_cmd == CMD_RA)
		return (_ra(stack_a, stack_b, NO_OPR));
	if (nbr_cmd == CMD_RB)
		return (_rb(stack_a, stack_b, NO_OPR));
	if (nbr_cmd == CMD_RR)
		return (_rr(stack_a, stack_b, NO_OPR));
	if (nbr_cmd == CMD_RRA)
		return (_rra(stack_a, stack_b, NO_OPR));
	if (nbr_cmd == CMD_RRB)
		return (_rrb(stack_a, stack_b, NO_OPR));
	if (nbr_cmd == CMD_RRR)
		return (_rrr(stack_a, stack_b, NO_OPR));
	return (ERR_CMD);
}

static void	_replace_newline(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
		{
			*str = '\0';
			return ;
		}
		str++;
	}
}

int	ps_exec_inputstr(t_node **stack_a, t_node **stack_b, char *cmd)
{
	int	nbr_cmd;

	if (cmd == NULL || *cmd == '\0')
		return (-1);
	_replace_newline(cmd);
	nbr_cmd = _char_to_cmd(cmd);
	if (nbr_cmd == -1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	if (_exec_cmd(stack_a, stack_b, nbr_cmd) != 1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (1);
}
