/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:17:43 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/14 10:25:34 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	_p_error(char *str)
{
	if (*str == '1')
		write(1, "Error\n", 6);
	else
	{
		while (*str != '\0')
		{
			write(1, str, 1);
			str++;
		}
	}
	return (-1);
}
