/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 09:51:08 by rusty             #+#    #+#             */
/*   Updated: 2022/01/29 16:50:47 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	get_score(int i, int size)
{
	int	tm;
	int	back;

	back = 2;
	tm = size / 2;
	if (size % 2)
		++tm;
	if (i <= tm)
		return (i);
	else
		while (size-- != i)
			++back;
	return (back);
}

void	first_input(t_ps *ps, char *input)
{	
	int		i;
	int		len;
	char	**args;

	args = ft_split(input, ' ');
	if (!args)
		error_exit_free(NULL);
	i = -1;
	len = -1;
	while (args[++len])
		;
	while (args[++i])
	{
		ft_clist_add_back(ps->a_stack, \
ft_clistnew(ft_atoi(args[i]), get_score(i + 1, len)));
	}
	free_split(args);
	ps->size_a = len;
}

void	second_input(t_ps *ps, int argc, char **argv)
{
	int	i;

	i = 0;
	// ft_printf("%s\n", argv[1]);
	while (argv[++i])
	{
	// ft_printf("%s\n", argv[i]);
		ft_clist_add_back(ps->a_stack, \
ft_clistnew(ft_atoi(argv[i]), get_score(i, argc - 1)));
	}
	ps->size_a = argc - 1;
}

t_ps	*input_ps(int argc, char **argv)
{
	t_ps	*ps;

	ps = (t_ps *)ft_calloc(sizeof(t_ps), 1);
	if (!ps)
		error_exit_free(NULL);
	init_stacks(ps);
	if (argc == 2)
		first_input(ps, argv[1]);
	else
		second_input(ps, argc, argv);
	return (ps);
}
