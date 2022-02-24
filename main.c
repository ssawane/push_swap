/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:00:14 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/09 13:49:36 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*str;
	int		*nums;
	t_list	*nodes;
	int		nums_count;
	int		*inds;

	if (ac > 1)
	{
		str = char_str_convert(av);
		nums = int_str_convert(str, &nums_count);
		inds = get_index(nums, nums_count);
		nodes = lst_nums_convert(nums, nums_count, inds);
		push_center(&nodes, inds, nums_count);
	}
}
