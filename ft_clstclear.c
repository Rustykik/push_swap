/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 07:45:42 by rusty             #+#    #+#             */
/*   Updated: 2022/01/29 23:14:06 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

void	ft_clstclear(t_clist **head)
{
	t_clist	*to_del;
	t_clist	*curr_lst;

	if (!head)
		return ;
	if (!*head)
		return ;
	to_del = *head;
	to_del->prev->next = NULL;
	t_clist *check = (*head);
	check = check->prev;
	// ft_printf("%p check next addr\n", check->next);
	// check = (*head);
	// while (check)
	// 	check= check->next;
	while (to_del)
	{
		curr_lst = to_del->next;
		// ft_printf("%p is about to del\n", to_del);
		ft_clistdellone(&to_del);
		to_del = curr_lst;
	}
	*head = NULL;
}
