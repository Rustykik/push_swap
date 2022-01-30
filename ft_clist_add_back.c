/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:27:24 by rusty             #+#    #+#             */
/*   Updated: 2022/01/30 07:06:09 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

void	ft_clist_add_back(t_clist **head, t_clist *new)
{
	if (!head)
		return ;
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
}
