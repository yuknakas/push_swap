/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:49:05 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/07 11:27:07 by yuknakas         ###   ########.fr       */
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
	int				section;
}	t_node;

//01_main operations
int			main(int argc, char **argv);
void		ps_push_swap(t_node **stack_a, t_node **stack_b);
//swap_3
void		_swap_3(t_node **stack);
void		_swap_3_execute(t_node **stack, int diff_value);
//swap_5
void		_swap_5(t_node **stack_a, t_node **stack_b, int stack_len);
int			_cost_target(t_node *first, int target);
//swap_large
void		_push_swap_large(t_node **a, t_node **b, int stack_len);
void		_swap_100(t_node **stack_a, t_node **stack_b);
void		_swap_500(t_node **stack_a, t_node **stack_b);
//utils
void		_longest_increacing_subseq(t_node *stack_a, size_t stack_size);
t_node		*_find_node(t_node *first, int target);
t_node		*_find_minimum(t_node *first);
t_node		*_find_maximum(t_node *first);
void		_fix_top(t_node **stack);
void		_clean_up(t_node *stack_a);

//02_preparation
int			ps_preparation(int argc, char **argv, t_node **a, t_node **b);
t_node		*_split_stack(char *str);
t_node		*_make_stack(int arr_len, char **char_arr, int should_free);
//utils
void		_free_char_dp(char **arr);
t_node		*ps_lstnew(int nb);
void		ps_lstadd_back(t_node **lst, t_node *new);
t_node		*ps_lstlast(t_node *lst);
void		ps_lstadd_front(t_node **lst, t_node *new);
void		ps_lstclear(t_node **stack);
int			ps_lstsize(t_node *lst);

//03_set_cost
void		ps_set_cost(t_node *stack_a, t_node *stack_b);
void		_set_target_cost_b(t_node *stack_a, t_node *stack_b);
void		_add_cost(t_node *stack);
t_node		*_next_set(t_node *first);
//utils
void		_ra_rb(t_node *target_node);
void		_ra_rrb(t_node *target_node);
void		_rra_rb(t_node *target_node);
void		_rra_rrb(t_node *target_node);
int			_find_cheapest(int a, int b, int c, int d);

//BON_01_Checker
int			_checker(t_node *stack_a, t_node *stack_b);

//04_swap
void		_set_stack_b(t_node **stack_a, t_node **stack_b, int target);
void		_set_big_stack_b(t_node **stack_a, t_node **stack_b);
void		_set_section_cost(t_node *target, t_node *stack_b);
int			_check_present_section(t_node *target, t_node *stack_b);
void		ps_execute_cheapest_node(t_node **a, t_node **b, char c);
void		_exc_min(t_node **a, t_node **b, t_node *min_node, char c);
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

//tester
void		_check_lis(t_node *stack_a);

#endif