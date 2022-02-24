/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:28:30 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/08 17:48:10 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_center(t_list **sta, int *inds, int nums_count)
{
	t_list	*stb;

	stb = NULL;
	if (nums_count == 3)
		three_elements(sta, 1);
	else if (nums_count == 4)
		four_elements(sta, &stb, inds, 0);
	else if (nums_count == 5)
		five_elements(sta, &stb, inds);
	else if (nums_count > 5)
		huge_elements(sta, &stb, nums_count);
}
