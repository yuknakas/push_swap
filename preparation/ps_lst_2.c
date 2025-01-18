/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:13:14 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/18 14:49:21 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ps_lstsize(t_node *lst)
{
	int		count;
	t_node	*first;

	if (lst == NULL)
		return (0);
	count = 1;
	first = lst;
	while (lst->next != first)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
