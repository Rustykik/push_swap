/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clistnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:20:41 by rusty             #+#    #+#             */
/*   Updated: 2022/01/29 16:52:02 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

t_clist	*ft_clistnew(long long val, long long elem_score)
{
	t_clist	*new;

	new = (t_clist *)ft_calloc(sizeof(t_clist), 1);
	if (!new)
		return (NULL);
	new->val = val;
	new->elem_score = elem_score;
	new->next = new;
	new->prev = new;
	return (new);
}
