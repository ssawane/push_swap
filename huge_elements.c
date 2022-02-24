/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huge_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:58:12 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/08 17:34:09 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nodes_counter(t_list **stck)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stck;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	second_step(t_main *lst)
{
	int	tmp;

	if (lst->min_a > 0)
	{
		tmp = lst->min_a;
		while (tmp > 0)
		{
			ft_rra_rrb(lst->stack_b, 2);
			tmp--;
		}
		tmp = lst->min_a;
		while (tmp > 0)
		{
			ft_pa(lst->stack_a, lst->stack_b);
			(*lst->stack_a)->flag = -1;
			ft_ra_rb(lst->stack_a, 1);
			tmp--;
		}
	}
}

void	first_step(t_main *lst, int iter)
{
	int	i;

	i = -1;
	while (++i < iter)
	{
		if ((*lst->stack_a)->index <= lst->mid)
		{
			ft_pb(lst->stack_a, lst->stack_b);
			if ((*lst->stack_b)->index == lst->min_a)
			{
				ft_ra_rb(lst->stack_b, 2);
				lst->min_a++;
			}
		}
		else
			ft_ra_rb(lst->stack_a, 1);
	}
}

void	huge_elements(t_list **sta, t_list **stb, int nums_count)
{
	t_main	lst;

	lst.mid = (nums_count - 1) / 2;
	lst.stack_a = sta;
	lst.stack_b = stb;
	lst.nums_total = nums_count;
	lst.min_a = 0;
	lst.len_a = nodes_counter(sta);
	lst.main_flag = 0;
	lst.string = NULL;
	first_step(&lst, lst.nums_total);
	second_step(&lst);
	third_step(&lst);
	giant_leap(&lst);
}
