/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:00:38 by rusty             #+#    #+#             */
/*   Updated: 2022/01/24 08:40:47 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_ps	*init_ps(void)
{
	t_ps	*ret;

	ret = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!ret)
		return (NULL);
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}
