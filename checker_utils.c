/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:26:24 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/08 13:10:49 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	correct_sorted(t_main *lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*lst->stack_a);
	tmp2 = tmp->next;
	while (tmp2->next && tmp2->index == tmp->index + 1)
	{
		tmp2 = tmp2->next;
		tmp = tmp->next;
	}
	if (tmp2 == ft_lstlast((*lst->stack_a)))
		return (1);
	return (0);
}

int	push_sa_sb_ss(t_main *lst, char *line)
{
	if (!ft_strcmp("sa\n", line))
		bonus_sa_sb(lst->stack_a);
	else if (!ft_strcmp("sb\n", line))
		bonus_sa_sb(lst->stack_b);
	else if (!ft_strcmp("ss\n", line))
		bonus_ss(lst->stack_a, lst->stack_b);
	else
		return (0);
	return (1);
}

int	push_pa_pb(t_main *lst, char *line)
{
	if (!ft_strcmp("pa\n", line))
		bonus_pa(lst->stack_a, lst->stack_b);
	else if (!ft_strcmp("pb\n", line))
		bonus_pb(lst->stack_a, lst->stack_b);
	else
		return (0);
	return (1);
}

int	push_ra_rb_rr_rra_rrb_rrr(t_main *lst, char *line)
{
	if (!ft_strcmp("ra\n", line))
		bonus_ra_rb(lst->stack_a);
	else if (!ft_strcmp("rb\n", line))
		bonus_ra_rb(lst->stack_b);
	else if (!ft_strcmp("rr\n", line))
		bonus_rr(lst->stack_a, lst->stack_b);
	else if (!ft_strcmp("rra\n", line))
		bonus_rra_rrb(lst->stack_a);
	else if (!ft_strcmp("rrb\n", line))
		bonus_rra_rrb(lst->stack_b);
	else if (!ft_strcmp("rrr\n", line))
		bonus_rrr(lst->stack_a, lst->stack_b);
	else
		return (0);
	return (1);
}
