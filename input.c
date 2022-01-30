/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 09:51:08 by rusty             #+#    #+#             */
/*   Updated: 2022/01/30 08:51:57 by rusty            ###   ########.fr       */
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

void	insert_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (++i < size)
	{
		j = i;
		while (j > 0 && arr[j] < arr[j - 1])
		{
			tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
			--j;
		}
	}
}

void	get_mid(t_ps *ps)
{
	int		i;
	int		*nums;
	t_clist	*tmp;

	nums = malloc(sizeof(int) * ps->size_a);
	if (!nums)
		error_exit_free(ps);
	i = -1;
	tmp = *ps->a_stack;
	while (++i < ps->size_a)
	{
		nums[i] = tmp->val;
		tmp = tmp->next;
	}
	insert_sort(nums, ps->size_a);
	ps->mid = nums[ps->size_a / 2];
	ps->max = nums[ps->size_a - 1];
	ps->min = nums[0];
	free(nums);
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
	get_mid(ps);
	return (ps);
}
