/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:28:30 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/02 16:49:01 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_center(t_list **sta, int *inds, int nums_count)
{
	t_list	*stb;

	stb = malloc(sizeof(t_list));
	if (nums_count == 3)
		three_elements(sta, 0, 1);
	else if (nums_count == 4)
		four_elements(sta, &stb, inds, 0);
	else if (nums_count == 5)
		five_elements(sta, &stb, inds);
	else if (nums_count > 5)
		huge_elements(sta, &stb, inds, nums_count);
}