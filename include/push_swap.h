/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:15:39 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/14 16:14:17 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

# define WRITE_OPR 1
# define NO_OPR 0
# define UNUSED 0

//defining node
typedef struct s_node
{
	int				nbr;
	int				cost;
	int				stack;
	struct s_node	*next;
}	t_node;

//main operations
int		main(int argc, char **argv);
int		_p_error(char *str);

//making stack_a
t_node	**_split_stack(char *str);
t_node	**_make_stack(int argc, char **argv, int should_free);
t_node	*_stack_error(t_node *new_stack);
t_node	*ps_lstnew(int nb);
void	ps_lstadd_back(t_node **lst, t_node *new);
t_node	*ps_lstlast(t_node *lst);
void	ps_lstadd_front(t_node **lst, t_node *new);
void	_free_stack(t_node **stack);

//swap 3 values
void	_swap_3(t_node **stack_a);
void	_swap_3_execute(t_node **stack_a, int diff_value);

//operations
void	_sa(t_node **stack_a, t_node **stack_b, int put_opr);
void	_sb(t_node **stack_a, t_node **stack_b, int put_opr);
void	_ss(t_node **stack_a, t_node **stack_b, int put_opr);
void	_pa(t_node **stack_a, t_node **stack_b, int put_opr);
void	_pb(t_node **stack_a, t_node **stack_b, int put_opr);
void	_ra(t_node **stack_a, t_node **stack_b, int put_opr);
void	_rb(t_node **stack_a, t_node **stack_b, int put_opr);
void	_rr(t_node **stack_a, t_node **stack_b, int put_opr);
void	_rra(t_node **stack_a, t_node **stack_b, int put_opr);
void	_rrb(t_node **stack_a, t_node **stack_b, int put_opr);
void	_rrr(t_node **stack_a, t_node **stack_b, int put_opr);

#endif