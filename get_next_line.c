/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:01:43 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/08 20:51:34 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(char const *s1)
{
	char	*res;
	int		i;

	if (s1 == 0)
		return (NULL);
	res = malloc(ft_strlen(s1) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	*ft_read(int fd)
{
	char	buf[1001];
	char	*str;
	ssize_t	rd;

	rd = read(fd, buf, 1000);
	if (rd <= 0)
		return (NULL);
	buf[rd] = '\0';
	str = ft_strdup(buf);
	return (str);
}

static char	*disconnect(char **rest)
{
	char	*p_n;
	char	*tmp;
	char	*str;

	if (ft_strlen(*rest) == 0)
	{
		free(*rest);
		*rest = NULL;
		return (NULL);
	}
	p_n = ft_strchr(*rest, '\n');
	if (p_n == 0)
	{
		str = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
		return (str);
	}
	*p_n = '\0';
	str = ft_strjoin(*rest, "\n");
	p_n++;
	tmp = *rest;
	*rest = ft_strdup(p_n);
	free(tmp);
	return (str);
}

static void	connect(char **rest, int fd)
{
	char	*line;
	char	*tmp;

	while (ft_strchr(*rest, '\n') == 0)
	{
		line = ft_read(fd);
		tmp = *rest;
		if (line == 0)
			break ;
		else
			*rest = ft_strjoin(*rest, line);
		free(tmp);
		free(line);
	}
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*str;

	if (fd < 0)
		return (NULL);
	if (rest == 0)
	{
		rest = ft_read(fd);
		if (rest == 0)
			return (NULL);
	}
	connect(&rest, fd);
	str = disconnect(&rest);
	return (str);
}
