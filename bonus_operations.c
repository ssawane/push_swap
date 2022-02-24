/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:49:16 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/08 10:13:52 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bonus_sa_sb(t_list **stck)
{
	t_list	*v1;
	t_list	*v2;
	t_list	*n;

	n = *(stck);
	if (n && n -> next)
	{
		v1 = *(stck);
		v2 = n -> next -> next;
		*(stck) = (*stck)->next;
		n = *(stck);
		n -> next = v1;
		n -> next -> next = v2;
	}
}

void	bonus_ss(t_list **sta, t_list **stb)
{
	bonus_sa_sb(sta);
	bonus_sa_sb(stb);
}

void	bonus_pa(t_list **sta, t_list **stb)
{
	t_list	*v1;

	if (*stb)
	{
		v1 = *sta;
		*sta = *stb;
		*stb = (*stb)-> next;
		(*sta)-> next = v1;
	}
}

void	bonus_pb(t_list **sta, t_list **stb)
{
	t_list	*v1;

	if (*sta)
	{
		v1 = *stb;
		*stb = *sta;
		*sta = (*sta)-> next;
		(*stb)->next = v1;
	}
}

void	bonus_ra_rb(t_list **stck)
{
	t_list	*tmp_first;
	t_list	*tmp_last;

	if ((*stck) && (*stck)->next)
	{
		tmp_last = ft_lstlast(*stck);
		tmp_first = *stck;
		*stck = (*stck)-> next;
		tmp_last -> next = tmp_first;
		tmp_first -> next = NULL;
	}
}
