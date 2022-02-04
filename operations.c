/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:49:16 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/04 12:25:13 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (tmp)
	{
		while(tmp -> next)
		{
			printf("data: %d, ", tmp -> data);
			printf("index: %d, ", tmp -> index);
			printf("flag: %d\n", tmp -> flag);
			tmp = tmp -> next;
		}
		printf("data: %d, ", tmp -> data);
		printf("index: %d, ", tmp -> index);
		printf("flag: %d\n", tmp -> flag);
		printf("%s\n", " ");
	}
} 

void	print_stacks(t_main *lst)
{
	printf("stack_a: %s\n", " ");
	print_list((*lst->stack_a));
	printf("stack_b: %s\n", " ");
	print_list(*(lst->stack_b));
}

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
		*(stck) = (*stck) -> next;
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
		*stb = (*stb) -> next;
		(*sta) -> next = v1;
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
		*sta = (*sta) -> next;
		(*stb)->next = v1;
		write (1, "pb", 2);
		write (1, "\n", 1);
	}
}

void	ft_ra_rb(t_list **stck, int index)
{
	t_list	*tmp_first;
	t_list	*tmp_last;

	if ((*stck)->next)
	{
		tmp_last = ft_lstlast(*stck);
		tmp_first = *stck;
		*stck = (*stck) -> next;
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

	tmp_first = *stck;
	tmp_last = ft_lstlast(*stck);
	tmp_alast = ft_almostlast(*stck);
	tmp_alast -> next = NULL;
	*stck = tmp_last;
	(*stck) -> next = tmp_first;
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

void	ft_rrr(t_list **sta, t_list **stb)
{
	ft_rra_rrb(sta, 0);
	ft_rra_rrb(stb, 0);
	write (1, "rrr", 3);
	write (1, "\n", 1);
}