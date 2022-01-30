/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:50:24 by rusty             #+#    #+#             */
/*   Updated: 2022/01/30 07:11:05 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	find_minmaxmid(long long *min, long long *max, long long *mid, t_ps *ps)
// {
// 	int		i;
// 	int		tm;
// 	t_clist	*stack;

// 	i = -1;
// 	stack = *ps->a_stack;
// 	*min = stack->val;
// 	*max = stack->val;
// 	*mid = stack->val;
// 	tm = ps->size_a / 2 + (ps->size_a % 2 * 1);
// 	// printf("timeless loop? %i\n", tm);
// 	while (++i < ps->size_a)
// 	{
// 	// printf("%lli min, %lli max, %lli mid compare to %lli\n", *min, *max, *mid, stack->val);

// 		if (*min > stack->val)
// 			*min = stack->val;
// 		if (*max < stack->val)
// 			*max = stack->val;
// 		if (i == tm - 1)
// 			*mid = stack->val;
// 		stack = stack->next;
// 	}
// 	// printf("%lli min, %lli max, %lli mid\n", *min, *max, *mid);
// 	// printf("timeless loop? - no\n");
// }

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

void	exec_rr_rra(t_ps *ps, t_act *act)
{
	while (act->count_a && act->count_b && act->dest_a == act->dest_b)
	{
		if (act->dest_a == 1 && act->dest_b == 1)
			rr(ps);
		else
			rrr(ps);
		--act->count_a;
		--act->count_b;
	}
}

void	execute_instruction(t_ps *ps, t_act *act)
{
	exec_rr_rra(ps, act);
	while (act->count_a > 0)
	{
		if (act->dest_a == 1)
			ra(ps);
		else
			rra(ps);
		--act->count_a;
	}
	while (act->count_b > 0)
	{
		if (act->dest_b == 1)
			rb(ps);
		else
			rrb(ps);
		act->count_b--;
	}
	pa(ps);
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

void	sort_b2a(t_ps *ps, long long min)
{
	t_act	*act;

	act = (t_act *)ft_calloc(sizeof(t_act), 1);
	if (!act)
		error_exit_free(ps);
	while (ps->size_b != 0)
	{
		act->count_a = -1;
		act->count_b = -1;
		act->dest_a = 0;
		act->dest_b = 0;
		get_sorting_scores(*ps->a_stack, ps->size_a);
		get_sorting_scores(*ps->b_stack, ps->size_b);
		minimum_insertion_steps(ps, act);
		execute_instruction(ps, act);
	}
	rotate_a_min2head(ps, min);
	free(act);
}

void	sort_3(t_ps *ps, long long max)
{
	if ((*ps->a_stack)->val == max)
		ra(ps);
	if ((*ps->a_stack)->next->val == max)
		rra(ps);
	if ((*ps->a_stack)->val > (*ps->a_stack)->next->val)
		sa(ps);
}

void	full_sort(long long min, long long max, long long mid, t_ps *ps)
{
	while (ps->size_a > 2)
	{
		if ((*ps->a_stack)->val != max && (*ps->a_stack)->val != min)
		{
			pb(ps);
			if ((*ps->b_stack)->val > mid)
				rb(ps);
		}
		else
			ra(ps);
	}
	if ((*ps->a_stack)->val < (*ps->a_stack)->next->val)
		sa(ps);
	pa(ps);
	sort_b2a(ps, min);
}

void	sort(t_ps *ps)
{
	if (ps->size_a == 2)
	{
		sa(ps);
		return ;
	}
	if (ps->size_a == 3)
		sort_3(ps, ps->max);
	else
		full_sort(ps->min, ps->max, ps->mid, ps);
}

int	check_sorted(t_clist *stack, int size)
{
	t_clist	*cur;
	int		i;

	cur = stack;
	i = -1;
	while (++i < size - 1)
	{
		if (cur->val > cur->next->val)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	solve(t_ps *ps)
{
	if (check_sorted(*ps->a_stack, ps->size_a))
		return ;
	sort(ps);
}

/* 

done pushswap 
learn git 

sort 3 ▚ DONE ▞

check maxint error via checklist
check presort if only ra needed 



find min max mid 
find least sorted 
smart push b 
normal elem score
then rot b push a
*/
