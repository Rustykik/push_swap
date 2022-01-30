/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 08:55:27 by rusty             #+#    #+#             */
/*   Updated: 2022/01/30 08:55:45 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_sorting_scores(t_clist *stack, long long size)
{
	int			i;
	t_clist		*stack_tmp;

	i = -1;
	stack_tmp = stack;
	while (++i <= size / 2)
	{
		stack_tmp->elem_score = i;
		stack_tmp->rot = 1;
		stack_tmp = stack_tmp->next;
	}
	if (size % 2 == 0)
		--i;
	while (--i > 0)
	{
		stack_tmp->elem_score = i;
		stack_tmp->rot = -1;
		stack_tmp = stack_tmp->next;
	}
}

int	smallest_found(t_ps *ps, long long data, int i)
{
	t_clist	*tmp_a;

	tmp_a = (*ps->a_stack);
	while (i < ps->size_a)
	{
		if (tmp_a->val < data && tmp_a->val > (*ps->b_stack)->val)
			return (1);
		tmp_a = tmp_a->next;
		++i;
	}
	return (0);
}

void	find_smallest(t_ps *ps, int i, int *actions, long long data)
{
	while (i < ps->size_a)
	{
		if ((*ps->a_stack)->val < data && \
		(*ps->a_stack)->val > (*ps->b_stack)->val)
			break ;
		*actions += 1;
		*ps->a_stack = (*ps->a_stack)->next;
		++i;
	}
}

void	find_util(t_ps *ps, int *actions)
{
	int			i;
	long long	data;

	i = -1;
	data = 0;
	while (++i < ps->size_a)
	{
		data = (*ps->a_stack)->val;
		if ((*ps->b_stack)->val > (*ps->a_stack)->val)
		{
			*actions += 1;
			if ((*ps->b_stack)->val < (*ps->a_stack)->next->val)
				break ;
			*ps->a_stack = (*ps->a_stack)->next;
		}
		else
			break ;
	}
	if (smallest_found(ps, data, i) == 1)
		find_smallest(ps, i, actions, data);
}

int	find_insert_place(t_ps *ps, int actions, t_act *act)
{
	int	count_actions;
	int	res;

	count_actions = 0;
	find_util(ps, &count_actions);
	if ((*ps->a_stack)->rot == -1)
		count_actions = ps->size_a - count_actions;
	if (actions == -1 || (count_actions + (*ps->b_stack)->elem_score) < actions)
	{
		act->dest_a = (*ps->a_stack)->rot;
		act->dest_b = (*ps->b_stack)->rot;
		act->count_a = count_actions;
		act->count_b = (*ps->b_stack)->elem_score;
		res = act->count_a + act->count_b;
		return (res);
	}
	else
		return (actions);
}
