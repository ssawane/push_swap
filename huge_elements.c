/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huge_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:58:12 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/02 20:09:38 by ssawane          ###   ########.fr       */
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

void	null_element_remove(t_main *lst)
{
	t_list	*last;
	t_list	*del;
	int		i;

	i = 0;
	last = ft_almostlast((*lst->stack_b));
	del = ft_lstlast((*lst->stack_b));
	last->next = NULL;
	free(del);
}

void	second_step(t_main *lst)
{
	int	tmp;

	if (lst->min_a > 0)
	{
		tmp = lst->min_a;
		while(tmp > 0)
		{
			ft_rra_rrb(lst->stack_b, 2);
			tmp--;
		}
		tmp = lst->min_a;
		while(tmp > 0)
		{
			ft_pa(lst->stack_a, lst->stack_b);
			(*lst->stack_a)->flag = -1;
			ft_ra_rb(lst->stack_a, 1);
			tmp--;
		}
	}
}

void	first_step(t_main *lst)
{
	int	i;
	int	fl;

	i = -1;
	fl = 0;
	while (++i < lst->nums_total)
	{
		if ((*lst->stack_a) -> index <= lst->mid)
		{
			ft_pb(lst->stack_a, lst->stack_b);
			if (!fl)
			{
				null_element_remove(lst);
				fl = 1;
			}
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

void	huge_elements(t_list **sta, t_list **stb, int *inds, int nums_count)
{
	t_main	lst;

	lst.mid = (nums_count - 1)/2;
	lst.indexes = inds;
	lst.stack_a = sta;
	lst.stack_b = stb;
	lst.nums_total = nums_count;
	lst.min_a = 0;
	lst.len_a = nodes_counter(sta);
	first_step(&lst);
	second_step(&lst);
	third_step(&lst);

	printf("min_a: %d\n", lst.min_a);
	printf("stack_a: %s\n", " ");
	print_list((*lst.stack_a));
	printf("stack_b: %s\n", " ");
	print_list(*(lst.stack_b));
}