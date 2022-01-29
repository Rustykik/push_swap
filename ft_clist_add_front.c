/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:32:59 by rusty             #+#    #+#             */
/*   Updated: 2022/01/29 23:03:05 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

void	ft_clist_add_front(t_clist **head, t_clist *new)
{
	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	new->prev = (*head)->prev;
	new->next = *head;
	(*head)->prev->next = new;
	(*head)->prev = new;
	*head = new;
}
