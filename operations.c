/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:49:16 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/08 17:45:02 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb(t_list **stck, int index)
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
		if (index == 1)
		{
			write (1, "sa", 2);
			write (1, "\n", 1);
		}
		else if (index == 2)
		{
			write (1, "sb", 2);
			write (1, "\n", 1);
		}
	}
}

void	ft_ss(t_list **sta, t_list **stb)
{
	ft_sa_sb(sta, 0);
	ft_sa_sb(stb, 0);
	write (1, "ss", 2);
	write (1, "\n", 1);
}

void	ft_pa(t_list **sta, t_list **stb)
{
	t_list	*v1;

	if (*stb)
	{
		v1 = *sta;
		*sta = *stb;
		*stb = (*stb)->next;
		(*sta)->next = v1;
		write (1, "pa", 2);
		write (1, "\n", 1);
	}
}

void	ft_pb(t_list **sta, t_list **stb)
{
	t_list	*v1;

	if (*sta)
	{
		v1 = *stb;
		*stb = *sta;
		*sta = (*sta)->next;
		(*stb)->next = v1;
		write (1, "pb", 2);
		write (1, "\n", 1);
	}
}
