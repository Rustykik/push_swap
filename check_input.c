/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 06:43:23 by rusty             #+#    #+#             */
/*   Updated: 2022/01/26 16:53:29 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	str_is_digit(char *str)
{
	if (*str == '+' || *str == '-')
		++str;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		++str;
	}
	return (1);
}

static void	check_duplicate(char **args, int free_args)
{
	int	i;
	int	j;

	i = 0;
	while (args[++i])
	{
		j = -1;
		while (++j < i)
		{
			if (ft_atoi(args[j]) == ft_atoi(args[i]))
			{
				if (free_args)
					free_split(args);
				error_wrong_args();
			}
		}
	}
}

static void	check_first(char *input)
{
	int		i;
	char	**args;

	args = ft_split(input, ' ');
	if (!args)
		error_exit_free(NULL);
	i = -1;
	while (args[++i])
	{
		if (!str_is_digit(args[i]))
		{
			free_split(args);
			error_wrong_args();
		}
	}
	check_duplicate(args, 1);
	free_split(args);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		exit(-1);
	if (argc == 2)
	{
		check_first(argv[++i]);
		return (1);
	}
	else
	{
		while (argv[++i])
		{
			if (!str_is_digit(argv[i]))
				error_wrong_args();
		}
		check_duplicate(argv, 0);
		return (2);
	}
}