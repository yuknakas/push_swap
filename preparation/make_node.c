/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:07:08 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/17 15:24:17 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	_preparation(int argc, char **argv, t_node **stack_a)
{
	if (argc < 2)
		return (1);
	if (argc == 2)
		*stack_a = _split_stack(argv[1]);
	else
		*stack_a = _make_stack((argc - 1), (argv + 1), NO_OPR);
	if (*stack_a == NULL)
		return (1);
	return (0);
}

static void	*_input_error(t_node **new_stack)
{
	ps_lstclear(new_stack);
	return (NULL);
}

static int	_check_nbr(char *str, int *nbr)
{
	int	i;

	i = 0;
	*nbr = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		if ((*nbr > (INT_MAX - (str[i] - '0')) / 10))
		{
			if (str[0] != '-' || *nbr != (INT_MAX - (str[i] - '0') + 1) / 10)
				return (1);
		}
		*nbr = *nbr * 10 + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		*nbr *= -1;
	return (0);
}

static int	_check_dup(t_node **stack_a)
{
	t_node	*current;
	t_node	*compare;

	if (stack_a == NULL || *stack_a == NULL)
		return (0);
	current = *stack_a;
	while (current->next != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			if (current->nbr == compare->nbr)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

t_node	*_make_stack(int arr_len, char **char_arr, int should_free)
{
	int		current_node;
	int		new_nbr;
	t_node	*new_stack;

	if (arr_len == 0 || *char_arr == NULL)
		return (NULL);
	new_stack = NULL;
	current_node = 0;
	while (current_node < arr_len)
	{
		if (_check_nbr(char_arr[current_node], &new_nbr) != 0)
			return (_input_error(&new_stack));
		ps_lstadd_back(&new_stack, ps_lstnew(new_nbr));
		current_node++;
	}
	if (should_free == WRITE_OPR)
		_free_chardp(char_arr);
	if (_check_dup(&new_stack) != 0)
		return (_input_error(&new_stack));
	return (new_stack);
}
