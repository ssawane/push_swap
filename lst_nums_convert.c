/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nums_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:05:56 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/19 00:33:00 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_nums_convert(t_list *nodes, int *nums, int nums_count)
{
	int		i;
	t_list	*unit;
	t_list	*ptr;

	i = 0;
	printf("%s\n", "1");
	while (i < nums_count)
	{
		unit = ft_lstnew(nums[i]);
		printf("data: %d\n", unit -> data);
		ft_lstadd_back(nodes, unit);
	//	printf("%d\n", (*nodes) -> data);
		free(unit);
		i++;
	}
	i = 0;
	printf("%s\n", "1q");
	// ptr = *nodes;
	// printf("%p\n", nodes -> next);
	// while (ptr -> next)
	// {
	// 	printf("%d\n", ptr -> data);
	// 	ptr = ptr -> next;
	// }
}