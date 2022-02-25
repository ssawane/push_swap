/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_step_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:31:44 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/25 09:06:00 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_flag(t_main *lst, int counter)
{
	t_list	*tmp;
	int		i;

	i = -1;
	tmp = (*lst->stack_a);
	lst->main_flag++;
	while (++i < counter)
	{
		tmp->flag = lst->main_flag;
		tmp = tmp->next;
	}
}

void	optimization(t_main *lst, int *i)
{
	if (*lst->stack_b)
	{
		if (ft_lstlast(*lst->stack_b)->index == lst->min_a)
		{
			ft_rra_rrb(lst->stack_b, 2);
			ft_pa(lst->stack_a, lst->stack_b);
			(*lst->stack_a)->flag = -1;
			ft_ra_rb(lst->stack_a, 1);
			lst->min_a++;
			*i = *i + 1;
		}
	}
	if ((*lst->stack_a)-> index == lst->min_a)
	{
		(*lst->stack_a)->flag = -1;
		ft_ra_rb(lst->stack_a, 1);
		lst->min_a++;
	}
}

void	third_step_cont(t_main *lst, int *counter, int *i)
{
	if ((*lst->stack_b)->index == lst->min_a)
	{
		ft_pa(lst->stack_a, lst->stack_b);
		(*lst->stack_a)->flag = -1;
		ft_ra_rb(lst->stack_a, 1);
		lst->min_a++;
		optimization(lst, i);
	}
	else if ((*lst->stack_b)->index >= lst->mid)
	{
		ft_pa(lst->stack_a, lst->stack_b);
		(*lst->stack_a)->flag = lst->main_flag;
		*counter = *counter + 1;
	}
	else
		ft_ra_rb(lst->stack_b, 2);
}

void	third_step(t_main *lst)
{
	int	i;
	int	counter;

	lst->len_b = nodes_counter(lst->stack_b);
	lst->max_order = max_order(lst);
	lst->mid = (lst->max_order - lst->min_a + 1) / 2 + lst->min_a + 1;
	while (lst->len_b > 3)
	{
		i = -1;
		counter = 0;
		while (++i < lst->len_b)
			third_step_cont(lst, &counter, &i);
		change_flag(lst, counter);
		lst->len_b = nodes_counter(lst->stack_b);
		lst->max_order = max_order(lst);
		lst->mid = (lst->max_order - lst->min_a + 1) / 2 + lst->min_a + 1;
	}
	last_three_elements_in_b(lst);
}
