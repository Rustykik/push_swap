/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 07:28:31 by rusty             #+#    #+#             */
/*   Updated: 2022/01/29 23:06:30 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char	**split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	init_stacks(t_ps *ps)
{
	ps->a_stack = (t_clist **)ft_calloc(sizeof(t_clist *), 1);
	ps->b_stack = (t_clist **)ft_calloc(sizeof(t_clist *), 1);
		// ft_printf("\n%p !!!!!!!!\n", ps->a_stack);
	if (!ps->a_stack || !ps->b_stack)
		error_exit_free(ps);
}

void	free_stacks(t_ps *ps)
{
	if (ps->a_stack)
	{
		// ft_printf("\n%p !!!!!!!!\n", ps->a_stack);
		ft_clstclear(ps->a_stack);
		// ft_printf("\n%p !!!!!!!!\n", ps->a_stack);
		free(ps->a_stack);
		ps->a_stack = NULL;
	}
	// ft_printf("free b\n");
	if (ps->b_stack)
	{
		ft_clstclear(ps->b_stack);
		free(ps->b_stack);
		ps->b_stack = NULL;
	}
}

void	free_ps(t_ps *ps)
{
	free_stacks(ps);
	free(ps);
}
