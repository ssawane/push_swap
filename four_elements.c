/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:36:14 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/08 14:13:19 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_five(int ind, int *inds)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (inds[i] == ind)
			return (i);
		i++;
	}
	return (-1);
}

int	find_index_four(int ind, int *inds)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (inds[i] == ind)
			return (i);
		i++;
	}
	return (-1);
}

void	four_elements_cont(t_list **sta, t_list **stb)
{
	ft_pb(sta, stb);
	three_elements(sta, 1);
	ft_pa(sta, stb);
}

void	four_elements(t_list **sta, t_list **stb, int *inds, int dt)
{
	int	a;

	a = find_index_four(dt, inds);
	if (a == 0)
		four_elements_cont(sta, stb);
	else if (a == 1)
	{
		ft_sa_sb(sta, 1);
		four_elements_cont(sta, stb);
	}
	else if (a == 2)
	{
		ft_rra_rrb(sta, 1);
		ft_rra_rrb(sta, 1);
		four_elements_cont(sta, stb);
	}
	else if (a == 3)
	{
		ft_rra_rrb(sta, 1);
		four_elements_cont(sta, stb);
	}
}

void	four_elements_ver_two(t_list **sta)
{
	if ((*sta)->next->index == 1)
		ft_sa_sb(sta, 1);
	else if ((*sta)->next->next->index == 1)
	{
		ft_ra_rb(sta, 1);
		ft_ra_rb(sta, 1);
	}
	else if ((*sta)->next->next->next->index == 1)
		ft_rra_rrb(sta, 1);
}
