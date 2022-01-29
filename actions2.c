/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 02:12:55 by rusty             #+#    #+#             */
/*   Updated: 2022/01/29 23:11:26 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	if (*ps->a_stack && ps->size_a > 1)
	{
		*ps->a_stack = (*ps->a_stack)->next;
		write(1, "ra\n", 3);
	//check_action(ps);
	}
}

void	rb(t_ps *ps)
{
	if (*ps->b_stack && ps->size_b > 1)
	{
		*ps->b_stack = (*ps->b_stack)->next;
		write(1, "rb\n", 3);
	//check_action(ps);
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
	write(1, "rr\n", 3);
	//check_action(ps);
}


void	rra(t_ps *ps)
{
	if (*ps->a_stack)
	{
		*ps->a_stack = (*ps->a_stack)->prev;
	}
	write(1, "rra\n", 4);
	//check_action(ps);
}

void	rrb(t_ps *ps)
{
	if (*ps->b_stack)
	{
	*ps->b_stack = (*ps->a_stack)->prev;
	}
	write(1, "rrb\n", 4);
	//check_action(ps);
}

void	rrr(t_ps *ps)
{
	if (*ps->a_stack)
	{
		*ps->b_stack = (*ps->a_stack)->prev;
	}
	if (*ps->b_stack)
	{
		*ps->b_stack = (*ps->b_stack)->prev;
	}
	write(1, "rrr\n", 4);
	//check_action(ps);
}
