/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:32:29 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/16 13:35:23 by ssawane          ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)&s[i]);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	slova(char *t, char c)
{
	int	sl;
	int	n;
	int	i;

	sl = 0;
	n = 0;
	i = 0;
	while (t[i])
	{
		if (t[i] != c && !n)
		{
			sl++;
			n = 1;
		}
		if (t[i] == c)
			n = 0;
		i++;
	}
	return (sl);
}

char	*zapis(char *t, int *start, int finish)
{
	char	*w;
	int		i;

	i = 0;
	w = malloc(sizeof(char) * (finish - *start + 1));
	while (*start < finish)
	{
		w[i] = t[*start];
		*start += 1;
		i++;
	}
	w[i] = '\0';
	*start = -1;
	return (w);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	int		n;
	int		j;

	i = 0;
	n = -1;
	j = 0;
	if (!s)
		return (NULL);
	str = malloc((slova((char *)s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (i <= (size_t)ft_strlen((char *)s))
	{
		if (s[i] != c && n < 0)
			n = i;
		else if ((s[i] == c || i == (size_t)ft_strlen((char *)s)) && n >= 0)
		{
			str[j++] = zapis((char *)s, &n, i);
		}
		i++;
	}
	str[j] = 0;
	return (str);
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

void	ft_error(char *err)
{
	write(1, "Error: ", 7);
	write(1, err, ft_strlen(err));
	write(1, "\n", 1);
	exit (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	long long		res;
	long long		k;

	i = 0;
	k = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			k = -1;
		i++;
	}
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
		ft_error("out of int range");
	return (res);
}