/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 07:13:35 by rusty             #+#    #+#             */
/*   Updated: 2022/01/26 19:03:04 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit_free(t_ps *ps)
{
	if (ps)
		free_ps(ps);
	exit(0);
}

void	error_wrong_args(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}
