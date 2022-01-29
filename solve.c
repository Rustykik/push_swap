/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:50:24 by rusty             #+#    #+#             */
/*   Updated: 2022/01/29 23:37:58 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_minmaxmid(long long *min, long long *max, long long *mid, t_ps *ps)
{
	int		i;
	int		tm;
	t_clist	*stack;

	i = -1;
	stack = *ps->a_stack;
	*min = stack->val;
	*max = stack->val;
	*mid = stack->val;
	tm = ps->size_a / 2 + (ps->size_a % 2 * 1);
	// printf("timeless loop? %i\n", tm);
	while (++i < ps->size_a)
	{
	// printf("%lli min, %lli max, %lli mid compare to %lli\n", *min, *max, *mid, stack->val);

		if (*min > stack->val)
			*min = stack->val;
		if (*max < stack->val)
			*max = stack->val;
		if (i == tm - 1)
			*mid = stack->val;
		stack = stack->next;
	}
	// printf("%lli min, %lli max, %lli mid\n", *min, *max, *mid);
	// printf("timeless loop? - no\n");
}

void	get_sorting_scores(t_clist *stack, long long size)
{
	int			back;
	int			i;
	long long	sze;
	t_clist		*stack_tmp;

	i = -1;
	stack_tmp = stack;
	while (++i < size)
	{
		back = 2;
		sze = size;
		if (i <= (size / 2 + (size % 2) * 1)) // maybe -1 
		{
			stack_tmp->elem_score = i;
			stack_tmp->rot = 1;
		}
		else
		{
			while (sze-- != i)
				++back;
			stack_tmp->elem_score = back;
			stack_tmp->rot = -1;
		}
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

void	find_util(t_ps *ps, int *actions)
{
	int			i;
	long long	data;

	i = -1;

	while (++i < ps->size_a)
	{
		data = (*ps->a_stack)->val;
		if ((*ps->b_stack)->val > (*ps->a_stack)->val)
		{
			*actions += 1;
			if ((*ps->b_stack)->val < (*ps->a_stack)->next->val)
				break ;
			ps->a_stack = &(*ps->a_stack)->next;
		}
		else
			break ;
	}
	if (smallest_found(ps, data, i))
	{
		// find_smallest(ps, i, )
		while (i < ps->size_a)
		{
			if ((*ps->b_stack)->val < data && (*ps->a_stack)->val > (*ps->b_stack)->val)
				break ;
			*actions += 1;
			++i;
		}
	}
	// ft_printf("we stock here\n");
}

int	find_insert_place(t_ps *ps, int actions, t_act *act)
{
	int	count_actions;
	int	res;

	count_actions = 0;
	find_util(ps, &count_actions);
	if ((*ps->a_stack)->rot == -1)
		count_actions = (*ps->a_stack)->elem_score - count_actions;
	if (actions == -1 || (count_actions + act->count_b) < actions)
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
	t_clist	**def_a;
	t_clist	**def_b;
	int		i;

	i = -1;
	actions = -1;
	def_a = ps->a_stack;
	def_b = ps->b_stack;
	while (++i < ps->size_b)
	{
		actions = find_insert_place(ps, actions, act);
		ps->a_stack = def_a;
		ps->b_stack = &(*ps->b_stack)->next;
	}
	ps->b_stack = def_b;
}

void	execute_instruction(t_ps *ps, t_act *act)
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
	// ft_printf("min is on %d", i);
	// sleep(10);
	if (i > ps->size_a / 2)
		while ((*ps->a_stack)->val != min)
			rra(ps);
	else
		while ((*ps->a_stack)->val != min)
			ra(ps);
}

void	sort_b2a(t_ps *ps, long long min) // , long long max, long long mid
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
		// ft_printf("we getted out of thet sht \n");
		// rb(ps);
		// ft_printf("%d %d %d %d", act->count_a, act->count_b, act->dest_a, act->dest_b);
		// sleep(10);
		execute_instruction(ps, act);
	}
/**/rotate_a_min2head(ps, min);
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
	while (ps->size_a > 3)
	{
	// printf("%lli min, %lli max, %lli mid\n", min, max, mid);

		// ft_printf("%i  ps cur val %i \n", ps->size_a, (*ps->a_stack)->val);
		if ((*ps->a_stack)->val != max && (*ps->a_stack)->val != min \
		&& (*ps->a_stack)->val != mid)
		{
			pb(ps);
			if (((*ps->a_stack)->val == max && (*ps->a_stack)->val == min \
		&& (*ps->a_stack)->val == mid) && (*ps->b_stack)->val > mid)
				rr(ps);
			else
				rb(ps);
		}
		else //(((*ps->a_stack)->val == max && (*ps->a_stack)->val == min && (*ps->a_stack)->val == mid))
			ra(ps);
		// sleep(7);
	}
	sort_3(ps, max);
	// pa(ps); // ?
	sort_b2a(ps, min); // , max, mid
}

void	sort(t_ps *ps)
{
	long long	max;
	long long	min;
	long long	mid;

	if (ps->size_a == 2)
	{
		sa(ps);
		return ;
	}
	find_minmaxmid(&min, &max, &mid, ps);
	// write(1, "finished\n", 8);
	// ft_printf("\n%i \n", ps->size_a);
	if (ps->size_a == 3)
		sort_3(ps, max);
	else
		full_sort(min, max, mid, ps);
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
	// ft_printf("not sorted\n");
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
