/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:11:11 by rusty             #+#    #+#             */
/*   Updated: 2022/01/28 08:44:48 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIST_H
# define CLIST_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_clist	t_clist;

struct s_clist
{
	long long	val;
	long long	elem_score;
	int			rot;
	t_clist		*next;
	t_clist		*prev;
};

void	ft_clist_add_back(t_clist **head, t_clist *new);
void	ft_clist_add_front(t_clist **head, t_clist *new);
void	ft_clistdellone(t_clist **clst);
t_clist	*ft_clistnew(long long val, long long elem_score);
void	ft_clstclear(t_clist **head);

#endif