/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:07:08 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/14 16:16:14 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	**_split_stack(char *str)
{
	char	**char_arr;
	int		arr_len;

	if (str == NULL)
		return (NULL);
	char_arr = ft_split(str, ' ');
	if (char_arr == NULL)
		return (NULL);
	arr_len = 0;
	while (char_arr[arr_len] != NULL)
		arr_len++;
	return (_make_stack(arr_len, char_arr, WRITE_OPR));
}

t_node	**_make_stack(int arr_len, char **char_arr, int should_free)
{
	int		current_node;
	int		new_nbr;
	t_node	**new_stack;

	if (arr_len == 0 || *char_arr == NULL)
		return (NULL);
	new_stack = malloc(sizeof(t_node *));
	if (new_stack == NULL)
		return (NULL);
	*new_stack = NULL;
	current_node = 0;
	while (current_node < arr_len)
	{
		new_nbr = ft_atoi(char_arr[current_node]);
		ps_lstadd_back(new_stack, ps_lstnew(new_nbr));
		current_node++;
	}
	if (should_free == WRITE_OPR)
		free(char_arr);
	return (new_stack);
}

