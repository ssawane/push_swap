/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:32:29 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/08 13:07:38 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

void	ft_error(void)
{
	write(2, "Error", 5);
	write(2, "\n", 1);
	exit (0);
}

void	ft_atoi_cont(const char **nptr, unsigned int *i, long long *k)
{
	while ((*nptr[*i] >= 9 && *nptr[*i] <= 13) || *nptr[*i] == 32)
		*i = *i + 1;
	if (*nptr[*i] == '-' || *nptr[*i] == '+')
	{
		if (*nptr[*i] == '-')
			*k = -1;
		*i = *i + 1;
	}
}

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	long long		res;
	long long		k;

	i = 0;
	k = 1;
	res = 0;
	ft_atoi_cont(&nptr, &i, &k);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0') * k;
		i++;
		if (res > 0 && k < 0)
			return (0);
		if (res < 0 && k > 0)
			return (-1);
	}
	if (res < -2147483648 || res > 2147483647)
		ft_error();
	return (res);
}
