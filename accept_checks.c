/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:20:42 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/25 10:24:53 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	already_sorted_check(int *nums, int amount)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (nums[j] < nums[i] && i < amount)
	{
		i++;
		j++;
	}
	if (i == amount)
		exit (0);
}

int	correct_minus_check(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		if (arr[i][j] == '-')
			j++;
		if (arr[i][j] < 48 || arr[i][j] > 57)
			ft_error();
		while (arr[i][j])
		{
			if (arr[i][j] >= 48 && arr[i][j] <= 57)
				j++;
			else
				ft_error();
		}
		i++;
	}
	return (0);
}

int	dup_check(char	**arr)
{
	int	i;
	int	j;

	i = -1;
	while (arr[++i])
	{
		j = i;
		while (arr[++j])
		{
			if (!ft_strcmp(arr[i], arr[j]))
				ft_error();
		}
	}
	return (0);
}

int	nums_counter(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	digit_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		exit(0);
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
		{
			if (str[i] != ' ' && str[i] != '-')
				ft_error();
		}
		i++;
	}
}
