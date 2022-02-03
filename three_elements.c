/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:02:00 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/02 22:43:27 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_elements(t_main *lst)
{
	t_list	*tmp;

	tmp = (*lst->stack_b);
	if (tmp->index > tmp->next->index)
		ft_ra_rb(lst->stack_b, 2);
}

void	two_one_zero(t_list **stck, int ab)
{
	// printf("%s\n", "two_one_zero");
	ft_sa_sb(stck, ab);
	ft_rra_rrb(stck, ab);
}

void	two_zero_one(t_list **stck, int ab)
{
	// printf("%s\n", "two_zero_one");
	ft_ra_rb(stck, ab);
}

void	zero_two_one(t_list **stck, int ab)
{
	// printf("%s\n", "zero_two_one");
	ft_rra_rrb(stck, ab);
	ft_sa_sb(stck, ab);
}

void	one_two_zero(t_list **stck, int ab)
{
	// printf("%s\n", "one_two_zero");
	ft_rra_rrb(stck, ab);
}

void	one_zero_two(t_list **stck, int ab)
{
	// printf("%s\n", "one_zero_two");
	ft_sa_sb(stck, ab);
}

void	three_elements(t_list **stck, int dt, int ab)
{
	if ((*stck) -> index == dt + 2 && (*stck) -> next -> index == dt + 1 &&
	(*stck) -> next -> next -> index == dt)
		two_one_zero(stck, ab);
	else if ((*stck) -> index == dt + 2 && (*stck) -> next -> index == dt &&
	(*stck) -> next -> next -> index == dt + 1)
		two_zero_one(stck, ab);
	else if ((*stck) -> index == dt && (*stck) -> next -> index == dt + 2 &&
	(*stck) -> next -> next -> index == dt + 1)
		zero_two_one(stck, ab);
	else if ((*stck) -> index == dt + 1 && (*stck) -> next -> index == dt + 2 &&
	(*stck) -> next -> next -> index == dt)
		one_two_zero(stck, ab);
	else if ((*stck) -> index == dt + 1 && (*stck) -> next -> index == dt &&
	(*stck) -> next -> next -> index == dt + 2)
		one_zero_two(stck, ab);
}