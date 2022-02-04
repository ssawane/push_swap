/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   giant_leap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:50:53 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/04 12:50:34 by ssawane          ###   ########.fr       */
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

// void	third_step_ver_two(t_main *lst)
// {
// 	int	i;
// 	int	counter;

// 	lst->len_b = nodes_counter(lst->stack_b);
// 	while(lst->len_b > 3)
// 	{
// 		i = -1;
// 		counter = 0;
// 		printf("len_b1: %d\n", lst->len_b);
// 		while(++i < lst->len_b)
// 		{
// 			if ((*lst->stack_b)->index == lst->min_a)
// 			{
// 				ft_pa(lst->stack_a, lst->stack_b);
// 				(*lst->stack_a)->flag = -1;
// 				ft_ra_rb(lst->stack_a, 1);
// 				lst->min_a++;
// 			}
// 			else if ((*lst->stack_b)->index >= lst->mid)
// 			{
// 				ft_pa(lst->stack_a, lst->stack_b);
// 				(*lst->stack_a)->flag = lst->main_flag;
// 				counter++;
// 			}
// 			else
// 				ft_ra_rb(lst->stack_b, 2);
// 		}
// 		if (counter > 10)
// 			change_flag(lst, counter);
// 		lst->len_b = nodes_counter(lst->stack_b);
// 		lst->mid = (lst->mid - lst->min_a + 1)/2 + lst->min_a + 1;
// 		printf("len_b2: %d\n", lst->len_b);
// 		printf("mid: %d\n", lst->mid);
// 		print_stacks(lst);
// 	}
// 	last_three_elements_in_b(lst);
// }

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
	//	print_stacks(lst);
		third_step(lst);
	//	print_stacks(lst);
		lst->counter_second_step++;
	}
	printf("iteracii: %d\n", lst->counter_second_step);
}

