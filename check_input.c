/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 06:43:23 by rusty             #+#    #+#             */
/*   Updated: 2022/01/31 14:10:56 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_less_maxint(const char *str)
{
	long long	ret;
	int			sig;

	ret = 0;
	sig = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'\
	|| *str == '\f' || *str == '\r')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sig *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = 10 * ret + *str - 48;
		if (ret > 2147483647 && sig == 1)
			return (0);
		if (ret > 2147483648 && sig == -1)
			return (0);
		++str;
	}
	return (1);
}

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
	if (!free_args)
		++i;
	while (args[++i])
	{
		j = -1;
		if (!free_args)
			++j;
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
		if (!str_is_digit(args[i]) || !is_less_maxint(args[i]))
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
			if (!str_is_digit(argv[i]) || !is_less_maxint(argv[i]))
				error_wrong_args();
		}
		check_duplicate(argv, 0);
		return (2);
	}
}
