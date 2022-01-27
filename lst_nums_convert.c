/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nums_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:05:56 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/27 18:06:17 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**lst_nums_convert(int *nums, int nums_count)
{
	int		i;
	t_list	**nodes;
	t_list	*unit;

	i = 0;
	*(nodes) = ft_lstnew(nums[i]);
	//printf("nums_count: %d\n", nums_count);
	while (++i < nums_count)
	{
		unit = ft_lstnew(nums[i]);
		ft_lstadd_back(nodes, unit);
	}
	// while (nodes -> next)
	// {
	// 	printf("data: %d\n", nodes -> data);
	// 	nodes = nodes -> next;
	// }
	return (nodes);
}