/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:49:16 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/08 17:46:01 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_rb(t_list **stck, int index)
{
	t_list	*tmp_first;
	t_list	*tmp_last;

	if ((*stck) && (*stck)->next)
	{
		tmp_last = ft_lstlast(*stck);
		tmp_first = *stck;
		*stck = (*stck)->next;
		tmp_last -> next = tmp_first;
		tmp_first -> next = NULL;
		if (index == 1)
		{
			write (1, "ra", 2);
			write (1, "\n", 1);
		}
		else if (index == 2)
		{
			write (1, "rb", 2);
			write (1, "\n", 1);
		}
	}
}

void	ft_rr(t_list **sta, t_list **stb)
{
	ft_ra_rb(sta, 0);
	ft_ra_rb(stb, 0);
	write (1, "rr", 2);
	write (1, "\n", 1);
}

void	ft_rra_rrb(t_list **stck, int index)
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
		(*stck)->next = tmp_first;
		if (index == 1)
		{
			write (1, "rra", 3);
			write (1, "\n", 1);
		}
		else if (index == 2)
		{
			write (1, "rrb", 3);
			write (1, "\n", 1);
		}
	}
}

void	ft_rrr(t_list **sta, t_list **stb)
{
	ft_rra_rrb(sta, 0);
	ft_rra_rrb(stb, 0);
	write (1, "rrr", 3);
	write (1, "\n", 1);
}
