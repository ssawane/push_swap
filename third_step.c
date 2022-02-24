/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:31:44 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/08 18:07:13 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_order(t_main *lst)
{
	t_list	*tmp;
	int		order;

	tmp = (*lst->stack_b);
	order = 0;
	while (tmp)
	{
		if (tmp->index > order)
			order = tmp->index;
		tmp = tmp->next;
	}
	return (order);
}

void	last_three_elements_in_b_cont(t_main *lst)
{
	two_elements(lst);
	ft_pa(lst->stack_a, lst->stack_b);
	(*lst->stack_a)->flag = -1;
	ft_ra_rb(lst->stack_a, 1);
	lst->min_a++;
	ft_pa(lst->stack_a, lst->stack_b);
	(*lst->stack_a)->flag = -1;
	ft_ra_rb(lst->stack_a, 1);
	lst->min_a++;
}

void	last_three_elements_in_b(t_main *lst)
{
	int	i;

	i = -1;
	if (lst->len_b == 1)
	{
		ft_pa(lst->stack_a, lst->stack_b);
		(*lst->stack_a)->flag = -1;
		ft_ra_rb(lst->stack_a, 1);
		lst->min_a++;
	}
	if (lst->len_b == 2)
		last_three_elements_in_b_cont(lst);
	else if (lst->len_b == 3)
	{
		three_elements(lst->stack_b, 2);
		while (++i < 3)
		{
			ft_pa(lst->stack_a, lst->stack_b);
			(*lst->stack_a)->flag = -1;
			ft_ra_rb(lst->stack_a, 1);
			lst->min_a++;
		}
	}
}
