/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gain_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:56:40 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/31 14:20:16 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_index(int *k, int *nums, int nums_count)
{
	int	i;

	*k = 0;
	while (*k < nums_count)
	{
		i = 0;
		while (nums[*k] <= nums[i] && i < nums_count)
			i++;
		if (i == nums_count)
			return (nums[*k]);
		*k = *k + 1;
	}
	return (0);
}

int	ft_max_check(int tmp, int number, int *nums, int nums_count)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (number == tmp)
		return (-1);
	while (i < nums_count)
	{
		if (number > nums[i] && nums[i] > tmp)
			k++;
		i++;
	}
	if (k == 0)
		return (0);
	else
		return (-1);
}

int	*get_index(int *nums, int nums_count)
{
	int	i;
	int	j;
	int	*res;
	int	tmp;

	i = 0;
	j = 0;
	res = (int *)malloc(sizeof(int) * nums_count);
	tmp = first_index(&i, nums, nums_count);
	res[i] = j++;
	while (j < nums_count)
	{
		i = -1;
		while (++i < nums_count)
		{
			if (nums[i] > tmp && !ft_max_check(tmp, nums[i], nums, nums_count))
			{
				res[i] = j++;
				tmp = nums[i];
			}
		}
	}
	return (res);
}

void	ft_index(t_list *nodes, int *inds)
{
	int	i;
	t_list	*tmp;

	i = 0;
	tmp = nodes;
	while (tmp)
	{
		tmp -> index = inds[i];
		tmp = tmp -> next;
		i++;
	}
}