/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:56:40 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/28 18:03:14 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int	first_index(int *k, int *nums, int nums_count)
{
	int	i;

	*k = 0;
	while (*k < nums_count)
	{
		i = 0;
		while (nums[*k] <= nums[i] && i < nums_count)
			i++;
		if (i == nums_count)
			return (nums[*k]);
		*k = *k + 1;
	}
	return (0);
}

int	next_index(int *k, int num, int *nums, int nums_count)
{
	int	i;

	*k = 0;
	printf("num: %d\n", num);
	while (*k < nums_count)
	{
		i = 0;
		if (nums[*k] > num)
		{
			while (nums[*k] < nums[i] && i < nums_count)
				i++;
		}
		printf("i: %d\n", i);
		if (i == nums_count)
			return (nums[*k]);
		*k = *k + 1;
	}
	return (0);
}

int	*ft_index(int *nums, int nums_count)
{
	int	i;
	int	j;
	int	*res;
	int	tmp;

	i = 0;
	j = 0;
	res = (int *)malloc(sizeof(int) * nums_count);
	tmp = first_index(&i, nums, nums_count);
	printf("tmp: %d\n", tmp);
	res[i] = j;
	while (++j < nums_count)
	{
		tmp = next_index(&i, tmp, nums, nums_count);
		printf("tmp: %d\n", tmp);
		res[i] = j;
	}
	return (res);
}

int	main(void)
{
	int		n1[] = {83, 7, 28, 81, 67};
	int		*nums;

	nums = ft_index(n1, 5);
	printf("nums[0]: %d\n", nums[0]);
	printf("nums[1]: %d\n", nums[1]);
	printf("nums[2]: %d\n", nums[2]);
	printf("nums[3]: %d\n", nums[3]);
	printf("nums[4]: %d\n", nums[4]);
	printf("nums[5]: %d\n", nums[5]);
	printf("nums[6]: %d\n", nums[6]);
	printf("nums[7]: %d\n", nums[7]);
}