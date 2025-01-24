/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:15:39 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 12:51:44 by yuknakas         ###   ########.fr       */
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
	int				correct_pos;
	struct s_node	*lis_prev;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rr;
	int				rrr;
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
static void	*_input_error(t_node *new_stack);
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
void		_push_swap_large(t_node **stack_a, t_node **stack_b, int stack_len);

//swap 3 values
void		_swap_3(t_node **stack);
void		_swap_3_execute(t_node **stack, int diff_value);

//swap 5 values
void		_swap_5(t_node **stack_a, t_node **stack_b, int stack_len);

//greatest arr
t_node		*_find_minimum(t_node *first);
t_node		*_find_maximum(t_node *first);
t_node		*_find_node(t_node *first, int target);
void		_longest_increacing_subseq(t_node *stack_a, size_t stack_size);

//cost
void		_set_cost(t_node *stack_a, t_node *stack_b, int target);
//individual costs
void		_set_self_cost(t_node *stack_a, t_node *stack_b);
void		_set_target_cost(t_node *stack_a, t_node *stack_b, int target);
void		_find_target_top(t_node *stack_a, int target, t_node *stack_b);
void		_find_target_bottom(t_node *stack_a, int target, t_node *stack_b);
t_node		*_next_set(t_node *first);
void		_set_edge(t_node *a, t_node *low, t_node *high, t_node *target);
void		_set_push_back_cost_a(t_node *stack_a, t_node *stack_b);
void		_set_target_cost_b(t_node *stack_a, t_node *stack_b);
//set cost
void		_add_cost_a(t_node *target);
void		_add_cost(t_node *stack_a, t_node *stack_b);
void		_set_cheapest(t_node *target_node);
int			_find_cheapest(int a, int b, int c, int d);
void		_ra_rb(t_node *target_node);
void		_ra_rrb(t_node *target_node);
void		_rra_rb(t_node *target_node);
void		_rra_rrb(t_node *target_node);

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
void		_clean_up(t_node *stack_a);

#endif