/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 08:24:06 by rusty             #+#    #+#             */
/*   Updated: 2022/01/29 19:56:24 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "clist.h"

# include <errno.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_ps				t_ps;
typedef struct s_actions		t_act;

struct s_ps
{
	long long	size_a;
	long long	size_b;
	long long	val;
	long long	elem_score;
	t_clist		**a_stack;
	t_clist		**b_stack;
	t_list		*actions;
	int			last_action;
	int			cur_action;
};

// enum	act
// {
// 	SA = 1;
// 	SB = 2;
// 	SS = 3;
// 	PA = 4;
// 	PB = 5;
// 	RA = 6;
// 	RB = 7;
// 	RR
// 	RRA
// 	RRB
// 	RRR
// }

struct s_actions
{
	int	count_a;
	int	count_b;
	int	dest_a;
	int	dest_b;
};

/*stack.c*/


/*input.c*/
t_ps	*input_ps(int argc, char **argv);

/*utils.c*/
void	free_split(char **split);
void	init_stacks(t_ps *ps);
void	free_stacks(t_ps *ps);
void	free_ps(t_ps *ps);

/*errors.c*/
void	error_exit_free(t_ps *ps);
void	error_wrong_args(void);

/*check_input.c*/
int		check_input(int argc, char **argv);

/*solve.c*/
void	solve(t_ps *ps);

/*actions*/

void	check_action(t_ps *ps);

void	pa(t_ps *ps);
void	pb(t_ps *ps);

void	sa(t_ps *ps);
void	sb(t_ps *ps);

void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);


#endif