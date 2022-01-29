/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 06:43:23 by rusty             #+#    #+#             */
/*   Updated: 2022/01/29 16:51:44 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		return (1);
	check_input(argc, argv);
	ps = input_ps(argc, argv);
	// for (int i = 0; i < ps->size_a; ++i) {
	// 	printf("%lli score :%lli \n", (**ps->a_stack).val, (**ps->a_stack).elem_score);
	// 	*ps->a_stack = (*ps->a_stack)->next;}
	solve(ps);
	free_ps(ps);
}
