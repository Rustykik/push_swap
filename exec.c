/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 08:56:55 by rusty             #+#    #+#             */
/*   Updated: 2022/01/30 08:57:14 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
