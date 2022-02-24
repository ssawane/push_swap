/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:49:16 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/08 10:14:15 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bonus_rr(t_list **sta, t_list **stb)
{
	bonus_ra_rb(sta);
	bonus_ra_rb(stb);
}

void	bonus_rra_rrb(t_list **stck)
{
	t_list	*tmp_first;
	t_list	*tmp_last;
	t_list	*tmp_alast;

	if ((*stck) && (*stck)->next)
	{
		tmp_first = *stck;
		tmp_last = ft_lstlast(*stck);
		tmp_alast = ft_almostlast(*stck);
		tmp_alast -> next = NULL;
		*stck = tmp_last;
		(*stck)-> next = tmp_first;
	}
}

void	bonus_rrr(t_list **sta, t_list **stb)
{
	bonus_rra_rrb(sta);
	bonus_rra_rrb(stb);
}
