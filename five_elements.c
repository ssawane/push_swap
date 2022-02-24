/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:36:14 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/08 14:30:12 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_elements_cont(t_list **sta, t_list **stb)
{
	ft_pb(sta, stb);
	four_elements_ver_two(sta);
	ft_pb(sta, stb);
	three_elements(sta, 1);
	ft_pa(sta, stb);
	ft_pa(sta, stb);
}

void	five_elements_a3(t_list **sta, t_list **stb)
{
	ft_rra_rrb(sta, 1);
	ft_rra_rrb(sta, 1);
	five_elements_cont(sta, stb);
}

void	five_elements(t_list **sta, t_list **stb, int *inds)
{
	int	a;

	a = find_index_five(0, inds);
	if (a == 0)
		five_elements_cont(sta, stb);
	else if (a == 1)
	{
		ft_sa_sb(sta, 1);
		five_elements_cont(sta, stb);
	}
	else if (a == 2)
	{
		ft_ra_rb(sta, 1);
		ft_sa_sb(sta, 1);
		five_elements_cont(sta, stb);
	}
	else if (a == 3)
		five_elements_a3(sta, stb);
	else if (a == 4)
	{
		ft_rra_rrb(sta, 1);
		five_elements_cont(sta, stb);
	}
}
