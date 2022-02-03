/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_five_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:36:14 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/02 16:47:35 by ssawane          ###   ########.fr       */
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

void	four_elements(t_list **sta, t_list **stb, int *inds, int dt)
{
	int	a;

	a = find_index_four(dt, inds);
	printf("a: %d\n", a);
	if (a == 0)
	{
		ft_pb(sta, stb);
		three_elements(sta, 1, 1);
		ft_pa(sta, stb);
	}
	else if (a == 1)
	{
		ft_sa_sb(sta, 1);
		ft_pb(sta, stb);
		three_elements(sta, 1, 1);
		ft_pa(sta, stb);
	}
	else if (a == 2)
	{
		ft_rra_rrb(sta, 1);
		ft_rra_rrb(sta, 1);
		ft_pb(sta, stb);
		three_elements(sta, 1, 1);
		ft_pa(sta, stb);
	}
	else if (a == 3)
	{
		ft_rra_rrb(sta, 1);
		ft_pb(sta, stb);
		three_elements(sta, 1, 1);
		ft_pa(sta, stb);
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

void	five_elements(t_list **sta, t_list **stb, int *inds)
{
	int	a;

	a = find_index_five(0, inds);
	printf("a: %d\n", a);
	if (a == 0)
	{
		ft_pb(sta, stb);
		four_elements_ver_two(sta);
		ft_pb(sta, stb);
		three_elements(sta, 2, 1);
		ft_pa(sta, stb);
		ft_pa(sta, stb);
	}
	else if (a == 1)
	{
		ft_sa_sb(sta, 1);
		ft_pb(sta, stb);
		four_elements_ver_two(sta);
		ft_pb(sta, stb);
		three_elements(sta, 2, 1);
		ft_pa(sta, stb);
		ft_pa(sta, stb);
	}
	else if (a == 2)
	{
		ft_ra_rb(sta, 1);
		ft_sa_sb(sta, 1);
		ft_pb(sta, stb);
		four_elements_ver_two(sta);
		ft_pb(sta, stb);
		three_elements(sta, 2, 1);
		ft_pa(sta, stb);
		ft_pa(sta, stb);
	}
	else if (a == 3)
	{
		ft_rra_rrb(sta, 1);
		ft_rra_rrb(sta, 1);
		ft_pb(sta, stb);
		four_elements_ver_two(sta);
		ft_pb(sta, stb);
		three_elements(sta, 2, 1);
		ft_pa(sta, stb);
		ft_pa(sta, stb);
	}
	else if (a == 4)
	{
		ft_rra_rrb(sta, 1);
		ft_pb(sta, stb);
		four_elements_ver_two(sta);
		ft_pb(sta, stb);
		three_elements(sta, 2, 1);
		ft_pa(sta, stb);
		ft_pa(sta, stb);
	}
}