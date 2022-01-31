/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 02:12:55 by rusty             #+#    #+#             */
/*   Updated: 2022/01/31 14:28:08 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	if (*ps->a_stack && ps->size_a > 1)
	{
		*ps->a_stack = (*ps->a_stack)->next;
	}
}

void	rb(t_ps *ps)
{
	if (*ps->b_stack && ps->size_b > 1)
	{
		*ps->b_stack = (*ps->b_stack)->next;
		write(1, "rb\n", 3);
	}
}

void	rr(t_ps *ps)
{
	if (*ps->a_stack)
	{
		*ps->a_stack = (*ps->a_stack)->next;
	}
	if (*ps->b_stack)
	{
		*ps->b_stack = (*ps->b_stack)->next;
	}
}

void	rra(t_ps *ps)
{
	if (*ps->a_stack)
	{
		*ps->a_stack = (*ps->a_stack)->prev;
	}
}

void	rrb(t_ps *ps)
{
	if (*ps->b_stack)
	{
		*ps->b_stack = (*ps->b_stack)->prev;
	}
}
