/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:20:42 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/31 17:39:21 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void already_sorted_check(int *nums, int amount)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while(nums[j] < nums[i] && i < amount)
	{
		i++;
		j++;
	}
	printf ("amount: %d\n", amount);
	printf ("i: %d\n", i);
	if (i == amount)
			ft_error("sorted already");
}

int	correct_minus_check(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while(arr[i])
	{
		j = 0;
		if (arr[i][j] == '-')
			j++;
		while (arr[i][j])
		{
			if (arr[i][j] >= 48 && arr[i][j] <= 57)
				j++;
			else
				ft_error("wrong format");
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
		while(arr[++j])
		{
			if (!ft_strcmp(arr[i], arr[j]))
				ft_error("duplicates found");
		}
	}
	return (0);
}

int	nums_counter(char	**arr)
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
		ft_error("too few arguments");
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
		{
			if (str[i] != ' ' && str[i] != '-')
				ft_error("only numbers allowed");
		}
		i++;
	}
}

int	*int_str_convert(char *str, int *n)
{
	int		*res;
	char	**arr;
	int		i;

	i = -1;
	digit_check(str);
	arr = ft_split(str, ' ');
	*n = nums_counter(arr);
	res = (int *)malloc(sizeof(int) * *n);
	if (!res)
		return (NULL);
	if (!dup_check(arr) && !correct_minus_check(arr))
	{
		while(arr[++i])
		{
			res[i] = ft_atoi(arr[i]);
			free(arr[i]);
		}
		free(arr);
	}
	already_sorted_check(res, *n);
	return (res);
}

char	*char_str_convert(char **av)
{
	int		i;
	int		j;
	char	*str;
	char	**splt;
	char	*tmp;

	i = 0;
	str = NULL;
	while (av[++i])
	{
		j = -1;
		splt = ft_split(av[i], ' ');
		while (splt[++j])
		{
			if (!str)
				str = splt[j];
			else
			{
				tmp = str;
				str = ft_strjoin(str, splt[j]);
				free(tmp);
				free(splt[j]);
			}
			tmp = str;
			str = ft_strjoin(str, " ");
			free(tmp);
		}
		free(splt);
	}
	return (str);
}
