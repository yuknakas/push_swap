/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:42:38 by yuknakas          #+#    #+#             */
/*   Updated: 2025/02/10 14:23:55 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../00_libft/gnl/get_next_line.h"
# include <stdlib.h>

# define WRITE_OPR 1
# define NO_OPR 0
# define UNUSED 0

# define CMD_SA 1
# define CMD_SB 2
# define CMD_SS 3
# define CMD_PA 4
# define CMD_PB 5
# define CMD_RA 6
# define CMD_RB 7
# define CMD_RR 8
# define CMD_RRA 9
# define CMD_RRB 10
# define CMD_RRR 11
# define ERR_CMD -1

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

int			main(int argc, char **argv);
int			ps_exec_inputstr(t_node **stack_a, t_node **stack_b, char *cmd);

//01_13
void		_clean_up(t_node *stack_a);

//02_preparation
int			ps_preparation(int argc, char **argv, t_node **a, t_node **b);
t_node		*_split_stack(char *str);
t_node		*_make_stack(int arr_len, char **char_arr, int should_free);
//utils
void		_free_char_dp(char **arr);
t_node		*ps_lstnew(int nb);
void		ps_lstadd_back(t_node **lst, t_node *new_node);
t_node		*ps_lstlast(t_node *lst);
void		ps_lstadd_front(t_node **lst, t_node *new_node);
void		ps_lstclear(t_node **stack);
int			ps_lstsize(t_node *lst);

//04_05
int			_checker(t_node *stack_a, t_node *stack_b);
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

# endif