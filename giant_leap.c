/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   giant_leap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:50:53 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/03 17:43:19 by ssawane          ###   ########.fr       */
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
	printf("%s\n", "q12");
	return (i);
}
void	push_to_b(t_main *lst, int flg_count)
{
	int	i;
	int	fl;

	i = -1;
	fl = 0;
	(*lst->stack_b) = malloc(sizeof(t_list));
	printf("%s\n", "qqq1");
	while (++i < flg_count)
	{
		if ((*lst->stack_a)->index == lst->min_a)
		{
			(*lst->stack_a)->flag = -1;
			ft_ra_rb(lst->stack_a, 1);
			lst->min_a++;
		}
		else
		{
			printf("%s\n", "qqq2");
			ft_pb(lst->stack_a, lst->stack_b);
			if (!fl)
			{
				printf("%s\n", "qqq3");
				null_element_remove(lst);
				fl = 1;
				printf("%s\n", "qqq5");
			}
		}
		printf("%s\n", "qqq4");
	}
}

// void	giant_leap(t_main *lst)
// {
// 	int	flg_count;
// 	int	act;

// //	while (lst->min_a != lst->nums_total)
// 	printf("min_A: %d \n", lst->min_a);
// 	printf("min_A: %d \n", lst->nums_total);
// 	act = 0;
// 	while (++act < 30)
// 	{
// 	//	lst->mid = (lst->mid - lst->min_a + 1)/2 + lst->min_a + 1;
// 		flg_count = flag_counter(lst->stack_a);
// 		printf("flg_count: %d\n", flg_count);
// 	//	third_step(lst);
// 		push_to_b(lst, flg_count);
// 		third_step(lst);
// 		flg_count = flag_counter(lst->stack_a);
// 		printf("flg_count: %d\n", flg_count);
// 		// flg_count = flag_counter(lst->stack_a);
// 		push_to_b(lst, flg_count);
// 		 third_step(lst);

// 		//act++;

// 	}
// }

void	giant_leap(t_main *lst)
{
	int	flg_count;

	flg_count = flag_counter(lst->stack_a);
	while (lst->min_a < lst->nums_total && flg_count != -1)
	{
		printf("flg_count: %d\n", flg_count);
		push_to_b(lst, flg_count);
		printf("%s\n", "q1");
		third_step(lst);
		printf("%s\n", "q2");
		flg_count = flag_counter(lst->stack_a);
		printf("%s\n", "q3");
		printf("%s\n", "q1");
		printf("min_A: %d \n", lst->min_a);
	}
}

