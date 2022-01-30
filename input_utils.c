/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 08:50:51 by rusty             #+#    #+#             */
/*   Updated: 2022/01/30 08:58:19 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (argv[++i])
	{
		ft_clist_add_back(ps->a_stack, \
ft_clistnew(ft_atoi(argv[i]), get_score(i, argc - 1)));
	}
	ps->size_a = argc - 1;
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
