/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:26:24 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/25 10:13:52 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	accept_commands(t_main *lst)
{
	int		a;
	char	*line;

	a = 0;
	line = get_next_line(0);
	while (line > 0)
	{
		if (ft_strchr(line, 's'))
			a = push_sa_sb_ss(lst, line);
		else if (ft_strchr(line, 'p'))
			a = push_pa_pb(lst, line);
		else if (ft_strchr(line, 'r'))
			a = push_ra_rb_rr_rra_rrb_rrr(lst, line);
		else
			return (0);
		if (a == 0)
		{
			free(line);
			return (0);
		}
		line = get_next_line(0);
	}
	free(line);
	return (1);
}

void	ft_checker(t_list **sta, int nums_count)
{
	t_list	*stb;
	t_main	lst;

	stb = NULL;
	lst.stack_a = sta;
	lst.stack_b = &stb;
	lst.last_index = nums_count;
	if (!accept_commands(&lst))
		ft_error();
	else if (!(*lst.stack_b) && correct_sorted(&lst))
	{
		write(1, "OK", 2);
		write(1, "\n", 1);
		exit(0);
	}
	else
	{
		write(1, "KO", 2);
		write(1, "\n", 1);
		exit(0);
	}
}

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
		ft_checker(&nodes, nums_count);
		ft_free_stacks(nodes);
	}
}
