/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:49:16 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/28 22:36:35 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list **lst)
{
	t_list	*tmp;

	tmp = *(lst);
	while(tmp -> next)
	{
		printf("data: %d\n", tmp -> data);
		printf("index: %d\n", tmp -> index);
		tmp = tmp -> next;
	}
	printf("data: %d\n", tmp -> data);
	printf("index: %d\n", tmp -> index);
	printf("%s\n", " ");
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
	t_list	*n1;
	t_list	*n2;

	n2 = *(stb);
	if (*(stb))
	{
		v1 = *(sta);
		*(sta) = *(stb);
		n1 = *(sta);
		*(stb) = n2 -> next;
		n1 -> next = v1;
		write (1, "pa", 2);
		write (1, "\n", 1);
	}
}
void	ft_pb(t_list **sta, t_list **stb)
{
	t_list	*v1;
	t_list	*n1;
	t_list	*n2;

	n2 = *(sta);
	if (*(sta))
	{
		v1 = *(stb);
		*(stb) = *(sta);
		n1 = *(stb);
		*(sta) = n2 -> next;
		(*stb)->next = v1;
		write (1, "pb", 2);
		write (1, "\n", 1);
	}
}

void	ft_ra_rb(t_list **stck, int index)
{
	t_list	*tmp_first;
	t_list	*tmp_last;

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
		write (1, "rra", 2);
		write (1, "\n", 1);
	}
	else if (index == 2)
	{
		write (1, "rrb", 2);
		write (1, "\n", 1);
	}
}

void	ft_rrr(t_list **sta, t_list **stb)
{
	ft_rra_rrb(sta, 0);
	ft_rra_rrb(stb, 0);
	write (1, "rrr", 2);
	write (1, "\n", 1);
}

// int	main(void)
// {
// 	t_list	**sta;
// 	t_list	**stb;
// 	int		n1[] = {83, 7, 28, 81, 67};
// 	int		n2[] = {32, 921, 68, 79, 17};

// 	sta = lst_nums_convert(n1, 5);
// 	printf("%s\n", "t1");
// 	stb = lst_nums_convert(n2, 5);

// 	//ft_sa_sb(stb, 2);
// 	//ft_pb(sta, stb);
// 	//ft_ss(sta, stb);
// 	//
// 	//ft_ra(sta);
// 	ft_rra_rrb(sta, 1);
// 	print_list(sta);
// 	//print_list(sta);
// }