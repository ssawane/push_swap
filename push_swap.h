/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:35:05 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/03 16:44:23 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //delete
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list {
	int				data;
	int				index;
	int				flag;
	struct s_list	*next;
}				t_list;

typedef struct	s_main {
	t_list		**stack_a;
	t_list		**stack_b;
	int			*indexes;
	int			nums_total;
	int			mid;
	int			min_a;
	int			len_a;
	int			len_b;
	int			counter_second_step;
	int			main_flag;
}				t_main;

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
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*lst_nums_convert(int *nums, int nums_count, int *inds);
void	ft_sa(t_list **nodes);
t_list	*ft_almostlast(t_list *lst);
void	ft_index(t_list *nodes, int *inds);
int		*get_index(int *nums, int nums_count);
int		ft_max_check(int tmp, int number, int *nums, int nums_count);
int		first_index(int *k, int *nums, int nums_count);
void	print_list(t_list *lst);
void	three_elements(t_list **stck, int dt, int ab);
void	four_elements(t_list **sta, t_list **stb, int *inds, int dt);
void	five_elements(t_list **sta, t_list **stb, int *inds);
void	huge_elements(t_list **sta, t_list **stb, int *inds, int nums_count);
void	ft_sa_sb(t_list **stck, int index);
void	ft_ss(t_list **sta, t_list **stb);
void	ft_pa(t_list **sta, t_list **stb);
void	ft_pb(t_list **sta, t_list **stb);
void	ft_ra_rb(t_list **stck, int index);
void	ft_rr(t_list **sta, t_list **stb);
void	ft_rra_rrb(t_list **stck, int index);
void	ft_rrr(t_list **sta, t_list **stb);
void	push_center(t_list **sta, int *inds, int nums_count);
int		nodes_counter(t_list **stck);
void	third_step(t_main *lst);
void	two_elements(t_main *lst);
void	first_step(t_main *lst, int iter);
void	giant_leap(t_main *lst);
void	second_step(t_main *lst);
void	null_element_remove(t_main *lst);

#endif