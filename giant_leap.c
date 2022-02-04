/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   giant_leap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:50:53 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/04 10:19:31 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	flag_counter(t_list **stck)
{
	int		i;
	t_list	*tmp;
	int		tmp_flg;

	i = 0;
	tmp = *stck;
	tmp_flg = tmp->flag;
	if (tmp_flg == -1)
		return (-1);
	while (tmp->flag == tmp_flg)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
void	push_to_b(t_main *lst, int flg_count)
{
	int	i;

	i = -1;
	while (++i < flg_count)
	{
		if ((*lst->stack_a)->index == lst->min_a)
		{
			(*lst->stack_a)->flag = -1;
			ft_ra_rb(lst->stack_a, 1);
			lst->min_a++;
		}
		else
			ft_pb(lst->stack_a, lst->stack_b);
	}
}

void	giant_leap(t_main *lst)
{
	int	flg_count;

	flg_count = flag_counter(lst->stack_a);
	lst->counter_second_step = 0;
	while (lst->min_a < lst->nums_total)
	{
		flg_count = flag_counter(lst->stack_a);
		push_to_b(lst, flg_count);
		// printf("stack_a: %s\n", " ");
		// print_list((*lst->stack_a));
		// printf("stack_b: %s\n", " ");
		// print_list(*(lst->stack_b));
		third_step(lst);
		// printf("stack_a: %s\n", " ");
		// print_list((*lst->stack_a));
		// printf("stack_b: %s\n", " ");
		// print_list(*(lst->stack_b));
		lst->counter_second_step++;
	}
	printf("iteracii: %d\n", lst->counter_second_step);
}

