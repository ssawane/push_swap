/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:31:44 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/02 22:47:48 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_check(t_main *lst)
{
	t_list	*tmp;
	int		i;

	i = -1;
	tmp = (*lst->stack_a);
	while(tmp && tmp->index == tmp->next->index + 1 && ++i <= lst->nums_total)
		tmp = (*lst->stack_a)->next;
	if (i == lst->nums_total)
		return (1);
	else
		return (0);	
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
	}
	if (lst->len_b == 2)
	{
		two_elements(lst);
		ft_pa(lst->stack_a, lst->stack_b);
		(*lst->stack_a)->flag = -1;
		ft_ra_rb(lst->stack_a, 1);
		ft_pa(lst->stack_a, lst->stack_b);
		(*lst->stack_a)->flag = -1;
		ft_ra_rb(lst->stack_a, 1);
	}
	else if (lst->len_b == 3)
	{
		three_elements(lst->stack_b, 0, 2);
		while (++i < 3)
		{
			ft_pa(lst->stack_a, lst->stack_b);
			(*lst->stack_a)->flag = -1;
			ft_ra_rb(lst->stack_a, 1);
		}
	}
}

void	third_step(t_main *lst)
{
	int	i;
	int	fl;
	int	fl2;

	fl = 1;
	fl2 = 0;
	lst->len_b = nodes_counter(lst->stack_b);
	while(lst->len_b > 3)
	{
		i = -1;
		lst->mid = (lst->mid - lst->min_a + 1)/2 + lst->min_a + 1;
		while(++i < lst->len_b)
		{
			if ((*lst->stack_b)->index == lst->min_a)
			{
				ft_pa(lst->stack_a, lst->stack_b);
				(*lst->stack_a)->flag = -1;
				ft_ra_rb(lst->stack_a, 1);
				lst->min_a++;
			}
			else if ((*lst->stack_b)->index >= lst->mid)
			{
				ft_pa(lst->stack_a, lst->stack_b);
				(*lst->stack_a)->flag = fl;
				fl2++;
			}
			else
				ft_ra_rb(lst->stack_b, 2);
		 }
		if (fl2)
			fl++;
		fl2 = 0;
		printf("len_b: %d\n", lst->len_b);
		lst->len_b = nodes_counter(lst->stack_b);
		printf("len_b: %d\n", lst->len_b);
	}
	last_three_elements_in_b(lst);
}