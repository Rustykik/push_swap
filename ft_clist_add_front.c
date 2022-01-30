/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:32:59 by rusty             #+#    #+#             */
/*   Updated: 2022/01/30 07:07:10 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

void	ft_clist_add_front(t_clist **head, t_clist *new)
{
	t_clist	*tmp;
	t_clist	*tmp_prev;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	new->prev = (*head)->prev;
	new->next = *head;
	tmp = (*head);
	tmp_prev = (*head)->prev;
	tmp_prev->next = new;
	tmp->prev = new;
	*head = new;
}
