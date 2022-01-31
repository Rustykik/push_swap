/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 08:59:21 by rusty             #+#    #+#             */
/*   Updated: 2022/01/31 13:35:46 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	minimum_insertion_steps(t_ps *ps, t_act *act)
{
	int		actions;
	t_clist	*def_a;
	t_clist	*def_b;
	int		i;

	i = -1;
	actions = -1;
	def_a = *ps->a_stack;
	def_b = *ps->b_stack;
	while (++i < ps->size_b)
	{
		actions = find_insert_place(ps, actions, act);
		*ps->a_stack = def_a;
		*ps->b_stack = (*ps->b_stack)->next;
	}
	*ps->b_stack = def_b;
}

void	rotate_a_min2head(t_ps *ps, long long min)
{
	int		i;
	t_clist	*tmp;

	i = -1;
	tmp = *ps->a_stack;
	while (++i < ps->size_a && tmp->val != min)
		tmp = tmp->next;
	if (i > ps->size_a / 2)
		while ((*ps->a_stack)->val != min)
			rra(ps);
	else
		while ((*ps->a_stack)->val != min)
			ra(ps);
}

long long	stack_min(t_clist *stack, int size)
{
	int			i;
	long long	min;
	t_clist		*tmp;

	tmp = stack;
	min = tmp->val;
	i = -1;
	while (++i < size)
	{
		if (tmp->val < min)
			min = tmp->val;
		tmp = tmp->next;
	}
	return (min);
}
