/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_ps_lst_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:37:46 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/04 11:58:34 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_node	*ps_lstnew(int nb)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->nbr = nb;
	new->next = new;
	new->prev = new;
	new->cost = 0;
	new->ra = 0;
	new->rb = 0;
	new->rr = 0;
	new->rra = 0;
	new->rrb = 0;
	new->rrr = 0;
	new->correct_pos = -1;
	new->lis_prev = NULL;
	new->section = -1;
	return (new);
}

void	ps_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*lst)->prev;
	last->next = new;
	new->prev = last;
	new->next = *lst;
	(*lst)->prev = new;
}

t_node	*ps_lstlast(t_node *lst)
{
	t_node	*first;

	if (lst == NULL)
		return (NULL);
	first = lst;
	while (lst->next != first && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ps_lstadd_front(t_node **lst, t_node *new)
{
	t_node	*last;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*lst)->prev;
	last->next = new;
	new->next = *lst;
	new->prev = last;
	(*lst)->prev = new;
	*lst = new;
}

void	ps_lstclear(t_node **stack)
{
	t_node	*tmp;

	if (stack == NULL)
		return ;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	write(1, "Error\n", 6);
}
