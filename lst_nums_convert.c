/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nums_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:05:56 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/28 16:59:01 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**lst_nums_convert(int *nums, int nums_count)
{
	int		i;
	t_list	**nodes;
	t_list	*unit;

	i = 1;
	*(nodes) = ft_lstnew(nums[0]);
	while (i < nums_count)
	{
		unit = ft_lstnew(nums[i]);
		ft_lstadd_back(nodes, unit);
		i++;
	}
	return (nodes);
}

int	*ft_index(int *nums, int nums_count)
{
	int	i;
	int	k;
	int	tmp;
	int	*res;

	i = 0;
	k = 0;
	while (k < nums_count)
	{
		i = 0;
		while (nums[k] < nums[i])
			i++;
		if (i == nums_count)
			j = nums[k];
		k++;
	}
	
}