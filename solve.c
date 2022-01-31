/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:50:24 by rusty             #+#    #+#             */
/*   Updated: 2022/01/31 13:36:02 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ps->size_a == 2)
	{
		if ((*ps->a_stack)->val > (*ps->a_stack)->next->val)
			sa(ps);
	}
	else
	{
		if ((*ps->a_stack)->val == max)
			ra(ps);
		if ((*ps->a_stack)->next->val == max)
			rra(ps);
		if ((*ps->a_stack)->val > (*ps->a_stack)->next->val)
			sa(ps);
	}
}

void	sort_3b(t_ps *ps)
{
	long long	min;

	min = stack_min((*ps->b_stack), ps->size_b);
	if (ps->size_b == 2)
	{
		if ((*ps->b_stack)->val < (*ps->b_stack)->next->val)
			sb(ps);
	}
	else
	{
		if ((*ps->b_stack)->val == min)
			rb(ps);
		if ((*ps->b_stack)->next->val == min)
			rrb(ps);
		if ((*ps->b_stack)->val < (*ps->b_stack)->next->val)
			sb(ps);
	}
}

void	full_sort(long long min, long long max, long long mid, t_ps *ps)
{
	int	size;

	size = ps->size_a;
	while (ps->size_a > 2)
	{
		if ((*ps->a_stack)->val != max && (*ps->a_stack)->val != min)
		{
			pb(ps);
			if (size > 5)
				if ((*ps->b_stack)->val > mid)
					rb(ps);
		}
		else
			ra(ps);
	}
	if ((*ps->a_stack)->val < (*ps->a_stack)->next->val)
		sa(ps);
	if (ps->size_b == 3)
	{
		sort_3b(ps);
		pa(ps);
		pa(ps);
		pa(ps);
	}
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
