/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:20:42 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/09 13:44:24 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*int_str_convert_cont(char *str, int *n, int i)
{
	int		*res;
	char	**arr;

	arr = ft_split(str, ' ');
	*n = nums_counter(arr);
	res = (int *)malloc(sizeof(int) * *n);
	if (!res)
		return (NULL);
	if (!dup_check(arr) && !correct_minus_check(arr))
	{
		while (arr[++i])
		{
			if (ft_strlen(arr[i]) > 11)
				ft_error();
			else
			{
				res[i] = ft_atoi(arr[i]);
				free(arr[i]);
			}
		}
		free(arr);
	}
	return (res);
}

int	*int_str_convert(char *str, int *n)
{
	int		*res;
	int		i;

	i = -1;
	res = int_str_convert_cont(str, n, i);
	already_sorted_check(res, *n);
	return (res);
}

void	char_str_convert_cont(char **av, int j, int i, char **str)
{
	char	*tmp;
	char	**splt;

	while (av[++i])
	{
		j = -1;
		splt = ft_split(av[i], ' ');
		while (splt[++j])
		{
			if (!*str)
				*str = splt[j];
			else
			{
				tmp = *str;
				*str = ft_strjoin(*str, splt[j]);
				free(tmp);
				free(splt[j]);
			}
			tmp = *str;
			*str = ft_strjoin(*str, " ");
			free(tmp);
		}
		free(splt);
	}
}

char	*char_str_convert(char **av)
{
	int		j;
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	j = 0;
	char_str_convert_cont(av, j, i, &str);
	digit_check(str);
	return (str);
}
