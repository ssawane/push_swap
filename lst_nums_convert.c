/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nums_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:05:56 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/31 14:15:37 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_nums_convert(int *nums, int nums_count, int *inds)
{
	int		i;
	t_list	*nodes;
	t_list	*unit;
	
	i = 1;
	nodes = ft_lstnew(nums[0]);
	while (i < nums_count)
	{
		unit = ft_lstnew(nums[i]);
		ft_lstadd_back(&nodes, unit);
		i++;
	}
	ft_index(nodes, inds);
	return (nodes);
}
