/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 10:09:14 by rusty             #+#    #+#             */
/*   Updated: 2022/01/31 15:49:30 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wrong_commad_exit(t_ps *ps)
{
	free_ps(ps);
	error_wrong_args();
}

void	solve(t_ps *ps)
{
	if (check_sorted(*ps->a_stack, ps->size_a))
		return ;
	sort(ps);
}

void	perform_action(t_ps *ps, char **line, int *legit_commans)
{
	if (ft_strncmp(*line, "rra\n", ft_strlen(*line)) == 0)
		rra(ps);
	else if (ft_strncmp(*line, "rrb\n", ft_strlen(*line)) == 0)
		rrb(ps);
	else if (ft_strncmp(*line, "ra\n", ft_strlen(*line)) == 0)
		ra(ps);
	else if (ft_strncmp(*line, "rb\n", ft_strlen(*line)) == 0)
		rb(ps);
	else if (ft_strncmp(*line, "sa\n", ft_strlen(*line)) == 0)
		sa(ps);
	else if (ft_strncmp(*line, "sb\n", ft_strlen(*line)) == 0)
		sb(ps);
	else if (ft_strncmp(*line, "pa\n", ft_strlen(*line)) == 0)
		pa(ps);
	else if (ft_strncmp(*line, "pb\n", ft_strlen(*line)) == 0)
		pb(ps);
	else if (ft_strncmp(*line, "rr\n", ft_strlen(*line)) == 0)
		rr(ps);
	else if (ft_strncmp(*line, "rrr\n", ft_strlen(*line)) == 0)
		rrr(ps);
	else
	{
		*legit_commans = 0;
	}
}

int	check_commands(t_ps *ps)
{
	char	*line;
	int		legit_commans;

	line = ft_get_next_line(0);
	legit_commans = 1;
	while (line)
	{
		perform_action(ps, &line, &legit_commans);
		free(line);
		line = ft_get_next_line(0);
		if (!line)
			break ;
	}
	return (legit_commans);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;
	int		ret;
	int		i;

	if (argc < 2)
		return (1);
	ret = 1;
	ps = input_ps(argc, argv);
	check_input(argc, argv);
	if (!check_commands(ps))
		wrong_commad_exit(ps);
	i = -1;
	while (++i < ps->size_a - 1)
	{
		if ((*ps->a_stack)->val > (*ps->a_stack)->next->val || ps->size_b != 0)
			ret = 0;
		(*ps->a_stack) = (*ps->a_stack)->next;
	}
	if (ret == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_ps(ps);
}
