/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_split_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:34:34 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 15:03:48 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_node	*_split_stack(char *str)
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
