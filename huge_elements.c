/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huge_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:58:12 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/01 17:58:04 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	huge_elements(t_list **sta, t_list **stb, int *inds, int nums_count)
{
	int		mid;
	int		i;

	mid = (nums_count - 1)/2;
	i = -1;
	printf("inds[0]: %d\n", inds[0]);
	printf("mid: %d\n", mid);
	while (++i < nums_count)
	{
		if ((*sta) -> index <= mid)
			ft_pb(sta, stb);
		else
			ft_ra_rb(sta, 1);
	}
	printf("stack_a: %s\n", " ");
	print_list(*sta);
	printf("stack_b: %s\n", " ");
	print_list(*stb);
}