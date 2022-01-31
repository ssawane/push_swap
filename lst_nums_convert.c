/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nums_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:05:56 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/30 23:12:18 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**lst_nums_convert(int *nums, int nums_count, int *inds)
{
	int		i;
	t_list	**nodes;
	t_list	*first;
	t_list	*unit;
	
	i = 1;
	first = ft_lstnew(nums[0]);
	nodes = &first;
	while (i < nums_count)
	{
		unit = ft_lstnew(nums[i]);
		ft_lstadd_back(nodes, unit);
		i++;
	}
	inds = ft_index(nodes, nums, nums_count);
	return (nodes);
}
