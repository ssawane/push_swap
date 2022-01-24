/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:35:05 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/19 00:25:51 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //delete
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list {
	int				data;
	struct s_list	*next;
}				t_list;

int		ft_atoi(const char *nptr);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*char_str_convert(char **av);
char	*ft_strchr(const char *s, int c);
void	ft_error(char *err);
int		ft_strcmp(const char *s1, const char *s2);
int		*int_str_convert(char *str, int *n);
t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list *lst, t_list *new);
void	lst_nums_convert(t_list *nodes, int *nums, int nums_count);

#endif