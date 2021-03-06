/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 06:43:23 by rusty             #+#    #+#             */
/*   Updated: 2022/01/31 13:35:01 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_ps *ps)
{
	if (check_sorted(*ps->a_stack, ps->size_a))
		return ;
	sort(ps);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		return (1);
	check_input(argc, argv);
	ps = input_ps(argc, argv);
	solve(ps);
	free_ps(ps);
}
