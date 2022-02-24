/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:02:00 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/08 18:18:50 by ssawane          ###   ########.fr       */
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
	ft_sa_sb(stck, ab);
	ft_rra_rrb(stck, ab);
}

void	zero_two_one(t_list **stck, int ab)
{
	ft_rra_rrb(stck, ab);
	ft_sa_sb(stck, ab);
}

void	three_elements(t_list **stck, int ab)
{
	int	t_ind1;
	int	t_ind2;
	int	t_ind3;

	t_ind1 = (*stck)->index;
	t_ind2 = (*stck)->next->index;
	t_ind3 = (*stck)->next->next->index;
	if (t_ind1 > t_ind2 && t_ind2 > t_ind3 && t_ind1 > t_ind3)
		two_one_zero(stck, ab);
	else if (t_ind1 > t_ind2 && t_ind2 < t_ind3 && t_ind1 > t_ind3)
		ft_ra_rb(stck, ab);
	else if (t_ind1 < t_ind2 && t_ind2 > t_ind3 && t_ind1 < t_ind3)
		zero_two_one(stck, ab);
	else if (t_ind1 < t_ind2 && t_ind2 > t_ind3 && t_ind1 > t_ind3)
		ft_rra_rrb(stck, ab);
	else if (t_ind1 > t_ind2 && t_ind2 < t_ind3 && t_ind1 < t_ind3)
		ft_sa_sb(stck, ab);
}
