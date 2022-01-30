/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:50:24 by rusty             #+#    #+#             */
/*   Updated: 2022/01/30 12:09:11 by rusty            ###   ########.fr       */
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
	else if (ps->size_a <= 5)
		sort_5(ps);
	else
		full_sort(ps->min, ps->max, ps->mid, ps);
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
