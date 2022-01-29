/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:27:24 by rusty             #+#    #+#             */
/*   Updated: 2022/01/29 16:51:18 by rusty            ###   ########.fr       */
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
	// t_clist *tmp = *head;
	// tmp = tmp->prev;
	// tmp->next = new;
	// new->prev = tmp;
	// tmp = *head;
	// tmp->prev = new;
	// new->next = tmp;
	// new->prev = (*head)->prev;
	// new->next = *head;
	// (*head)->prev->next = new;
	// (*head)->prev = new;
	new->prev = (*head)->prev;
	// write(1, "lol1\n", 5);
	new->next = *head;
	// write(1, "lol2\n", 5);
	// ft_printf("%p\n", (*head)->prev);
	(*head)->prev->next = new;
	// write(1, "lol3\n", 5);
	(*head)->prev = new;
	// write(1, "lol4\n", 5);
}
