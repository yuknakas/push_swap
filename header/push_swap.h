/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:15:39 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/18 14:30:06 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/header/libft.h"
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
	struct s_node	*prev;
}	t_node;

//main operations
int			main(int argc, char **argv);
int			_p_error(char *str);
void		final_results(t_node *stack_a);

//preparation (making stack_a)
//preparation/split_stack.c
t_node		*_split_stack(char *str);
void		_free_chardp(char **str);
//preparation/make_node.c
int			_preparation(int argc, char **argv,
				t_node **stack_a, t_node **stack_b);
static void	*_input_error(t_node **new_stack);
static int	_check_nbr(char *str, int *nbr);
static int	_check_dup(t_node *stack);
t_node		*_make_stack(int arr_len, char **char_arr, int should_free);
//preparation/ps_lst.c
t_node		*ps_lstnew(int nb);
void		ps_lstadd_back(t_node **lst, t_node *new);
t_node		*ps_lstlast(t_node *lst);
void		ps_lstadd_front(t_node **lst, t_node *new);
void		ps_lstclear(t_node **stack);
int			ps_lstsize(t_node *lst);

//push_swap BEGINS!
//control
void		_push_swap(t_node **stack_a, t_node **stack_b);

//swap 3 values
void		_swap_3(t_node **stack);
void		_swap_3_execute(t_node **stack, int diff_value);

//swap 5 values
void		_swap_5(t_node **stack_a, t_node **stack_b, int stack_len);

//operations
int			_sa(t_node **stack_a, t_node **stack_b, int put_opr);
int			_sb(t_node **stack_a, t_node **stack_b, int put_opr);
int			_ss(t_node **stack_a, t_node **stack_b, int put_opr);
int			_pa(t_node **stack_a, t_node **stack_b, int put_opr);
int			_pb(t_node **stack_a, t_node **stack_b, int put_opr);
int			_ra(t_node **stack_a, t_node **stack_b, int put_opr);
int			_rb(t_node **stack_a, t_node **stack_b, int put_opr);
int			_rr(t_node **stack_a, t_node **stack_b, int put_opr);
int			_rra(t_node **stack_a, t_node **stack_b, int put_opr);
int			_rrb(t_node **stack_a, t_node **stack_b, int put_opr);
int			_rrr(t_node **stack_a, t_node **stack_b, int put_opr);

//free everything
void		_clean_up(t_node *stack_a, t_node *stack_b);

#endif