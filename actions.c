/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:54:34 by rusty             #+#    #+#             */
/*   Updated: 2022/01/29 23:11:09 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	check_action(t_ps *ps)
// {
	// int j = 0;
	// printf("==================\n\n");
	// printf("s-a\ts-b\n\n");
	// for (int i = 0; i < ps->size_a; ++i) {
	// 		printf("%lli \t", (**ps->a_stack).val);
	// 		*ps->a_stack = (*ps->a_stack)->next;
	// 		if (j < ps->size_b) {
	// 			printf("%lli \n", (**ps->b_stack).val);
	// 			*ps->b_stack = (*ps->b_stack)->next;
	// 			++j;
	// 		}
	// 		else 
	// 			printf("\n");
	// }
	// printf("==================\n\n");
	// sleep(3);
// }

void	sa(t_ps *ps)
{
	long long	tmp;

	if (ps->size_a > 1)
	{
		tmp = (*ps->a_stack)->val;
		(*ps->a_stack)->val = (*ps->a_stack)->next->val;
		(*ps->a_stack)->next->val = tmp;
	}
	write(1, "sa\n", 3);
	//check_action(ps);
}

void	sb(t_ps *ps)
{
	long long	tmp;

	if (ps->size_b > 1)
	{
		tmp = (*ps->b_stack)->val;
		(*ps->b_stack)->val = (*ps->b_stack)->next->val;
		(*ps->b_stack)->next->val = tmp;
	}
	write(1, "sb\n", 3);
	//check_action*(ps);

}

void	pa(t_ps *ps)
{
	if (ps->size_b > 0)
	{
		++ps->size_a;
		--ps->size_b;
		if (ps->size_b == 0)
		{
			ft_clist_add_front(ps->a_stack, ft_clistnew((*ps->b_stack)->val, 0));
			ft_clistdellone(ps->b_stack);
			*ps->b_stack = NULL;
		}
		else
		{
			ft_clist_add_front(ps->a_stack, ft_clistnew((*ps->b_stack)->val, 0));
			t_clist *tmp = (*ps->b_stack);
			(*ps->b_stack)->prev->next = (*ps->b_stack)->next;
			(*ps->b_stack)->next->prev = (*ps->b_stack)->prev;
			(*ps->b_stack) = (*ps->b_stack)->next;
			ft_clistdellone(&tmp);
		}
	}
	write(1, "pb\n", 3);
	//check_action(ps);

}

void	pb(t_ps *ps)
{
	if (ps->size_a > 0)
	{
		++ps->size_b;
		--ps->size_a;
		if (ps->size_a == 0)
		{
			ft_clist_add_front(ps->b_stack, ft_clistnew((*ps->a_stack)->val, 0));
			ft_clistdellone(ps->a_stack);
			*ps->a_stack = NULL;
		}
		else
		{
			ft_clist_add_front(ps->b_stack, ft_clistnew((*ps->a_stack)->val, 0));
			// t_clist *tmp_next = (*ps->a_stack)->next;
			// t_clist *tmp_prev = (*ps->a_stack)->prev;
			// tmp_prev->next = tmp_next;
			// tmp_next->prev = tmp_prev;
			// (*ps->a_stack) = tmp_next;

			t_clist *tmp = (*ps->a_stack);
			(*ps->a_stack)->prev->next = (*ps->a_stack)->next;
			(*ps->a_stack)->next->prev = (*ps->a_stack)->prev;
			(*ps->a_stack) = (*ps->a_stack)->next;
			ft_clistdellone(&tmp);
			tmp = NULL;
		}
	}
	write(1, "pb\n", 3);
	//check_action(ps);
}