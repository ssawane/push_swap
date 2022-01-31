/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:02:00 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/31 17:15:40 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_one_zero(t_list **stck)
{
	// printf("%s\n", "two_one_zero");
	ft_sa_sb(stck, 1);
	ft_rra_rrb(stck, 1);
}

void	two_zero_one(t_list **stck)
{
	// printf("%s\n", "two_zero_one");
	ft_ra_rb(stck, 1);
}

void	zero_two_one(t_list **stck)
{
	// printf("%s\n", "zero_two_one");
	ft_rra_rrb(stck, 1);
	ft_sa_sb(stck, 1);
}

void	one_two_zero(t_list **stck)
{
	// printf("%s\n", "one_two_zero");
	ft_rra_rrb(stck, 1);
}

void	one_zero_two(t_list **stck)
{
	// printf("%s\n", "one_zero_two");
	ft_sa_sb(stck, 1);
}

void	three_elements(t_list **stck, int dt)
{
	if ((*stck) -> index == dt + 2 && (*stck) -> next -> index == dt + 1 &&
	(*stck) -> next -> next -> index == dt)
		two_one_zero(stck);
	else if ((*stck) -> index == dt + 2 && (*stck) -> next -> index == dt &&
	(*stck) -> next -> next -> index == dt + 1)
		two_zero_one(stck);
	else if ((*stck) -> index == dt && (*stck) -> next -> index == dt + 2 &&
	(*stck) -> next -> next -> index == dt + 1)
		zero_two_one(stck);
	else if ((*stck) -> index == dt + 1 && (*stck) -> next -> index == dt + 2 &&
	(*stck) -> next -> next -> index == dt)
		one_two_zero(stck);
	else if ((*stck) -> index == dt + 1 && (*stck) -> next -> index == dt &&
	(*stck) -> next -> next -> index == dt + 2)
		one_zero_two(stck);
}

// int	main(void)
// {
// 	t_list	**stck;
// 	t_list	**st2;
// 	int		n1[] = {8, 73, 28};

// 	stck = lst_nums_convert(n1, 3);
// 	st2 = stck;
// 	//print_list(stck);
// 	three_elements(st2);
// 	//print_list(stck);
	
// }