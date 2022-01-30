/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 08:24:06 by rusty             #+#    #+#             */
/*   Updated: 2022/01/30 11:57:40 by rusty            ###   ########.fr       */
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
	int			mid;
	int			max;
	int			min;
};

struct s_actions
{
	int	count_a;
	int	count_b;
	int	dest_a;
	int	dest_b;
};

/*solve.c*/
void		solve(t_ps *ps);
void		sort_3(t_ps *ps, long long max);

/*solve_utils.c*/
void		rotate_a_min2head(t_ps *ps, long long min);
void		sort_5(t_ps *ps);

/*exec.c*/
void		execute_instruction(t_ps *ps, t_act *act);

/*find.c*/
void		get_sorting_scores(t_clist *stack, long long size);
void		minimum_insertion_steps(t_ps *ps, t_act *act);
int			find_insert_place(t_ps *ps, int actions, t_act *act);

/*input.c*/
t_ps		*input_ps(int argc, char **argv);
long long	get_score(int i, int size);

/*input_utils.c*/
int			check_sorted(t_clist *stack, int size);

/*utils.c*/
void		free_split(char **split);
void		init_stacks(t_ps *ps);
void		free_stacks(t_ps *ps);
void		free_ps(t_ps *ps);

/*errors.c*/
void		error_exit_free(t_ps *ps);
void		error_wrong_args(void);

/*check_input.c*/
int			check_input(int argc, char **argv);
void		get_mid(t_ps *ps);
void		second_input(t_ps *ps, int argc, char **argv);
void		first_input(t_ps *ps, char *input);


/*actions*/

// void	check_action(t_ps *ps);

void		pa(t_ps *ps);
void		pb(t_ps *ps);

void		sa(t_ps *ps);
void		sb(t_ps *ps);

void		ra(t_ps *ps);
void		rb(t_ps *ps);
void		rr(t_ps *ps);
void		rra(t_ps *ps);
void		rrb(t_ps *ps);
void		rrr(t_ps *ps);

#endif