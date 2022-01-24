/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:00:14 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/19 00:38:36 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*str;
	int		*nums;
	t_list	*nodes;
	int		nums_count;

//	nodes -> next = NULL;
	printf("%p\n", nodes);
	printf("%p\n", nodes -> next);

	if (ac > 0)
	{
		str = char_str_convert(av);
		printf("str: %s\n", str);
		nums = int_str_convert(str, &nums_count);

		printf("nums[0]: %d\n", nums[0]);
		printf("nums[1]: %d\n", nums[1]);
		printf("nums[2]: %d\n", nums[2]);
		printf("nums[3]: %d\n", nums[3]);
		printf("nums[4]: %d\n", nums[4]);
		printf("nums[5]: %d\n", nums[5]);
		printf("nums[6]: %d\n", nums[6]);
		printf("nums[7]: %d\n", nums[7]);
		lst_nums_convert(nodes, nums, nums_count);

	}
//	while (1);
}