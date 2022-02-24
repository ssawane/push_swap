/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:35:05 by ssawane           #+#    #+#             */
/*   Updated: 2022/02/08 21:01:06 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list {
	int				data;
	int				index;
	int				flag;
	struct s_list	*next;
}				t_list;

typedef struct s_main {
	t_list		**stack_a;
	t_list		**stack_b;
	char		*string;
	int			nums_total;
	int			mid;
	int			min_a;
	int			len_a;
	int			len_b;
	int			main_flag;
	int			max_order;
	int			last_index;
}				t_main;

int		*int_str_convert(char *str, int *n);
int		*get_index(int *nums, int nums_count);
int		ft_atoi(const char *nptr);
int		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_max_check(int tmp, int number, int *nums, int nums_count);
int		first_index(int *k, int *nums, int nums_count);
int		nodes_counter(t_list **stck);
int		max_order(t_main *lst);
int		correct_minus_check(char **arr);
int		dup_check(char	**arr);
int		nums_counter(char **arr);
int		push_sa_sb_ss(t_main *lst, char *line);
int		push_pa_pb(t_main *lst, char *line);
int		push_ra_rb_rr_rra_rrb_rrr(t_main *lst, char *line);
int		correct_sorted(t_main *lst);
int		find_index_five(int ind, int *inds);
int		max_order(t_main *lst);

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*char_str_convert(char **av);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char const *s1);
char	*get_next_line(int fd);

t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
t_list	*lst_nums_convert(int *nums, int nums_count, int *inds);
t_list	*ft_almostlast(t_list *lst);

void	ft_error(void);
void	ft_sa(t_list **nodes);
void	ft_index(t_list *nodes, int *inds);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	print_list(t_list *lst);
void	three_elements(t_list **stck, int ab);
void	four_elements(t_list **sta, t_list **stb, int *inds, int dt);
void	five_elements(t_list **sta, t_list **stb, int *inds);
void	huge_elements(t_list **sta, t_list **stb, int nums_count);
void	ft_sa_sb(t_list **stck, int index);
void	ft_ss(t_list **sta, t_list **stb);
void	ft_pa(t_list **sta, t_list **stb);
void	ft_pb(t_list **sta, t_list **stb);
void	ft_ra_rb(t_list **stck, int index);
void	ft_rr(t_list **sta, t_list **stb);
void	ft_rra_rrb(t_list **stck, int index);
void	ft_rrr(t_list **sta, t_list **stb);
void	push_center(t_list **sta, int *inds, int nums_count);
void	third_step(t_main *lst);
void	two_elements(t_main *lst);
void	first_step(t_main *lst, int iter);
void	giant_leap(t_main *lst);
void	second_step(t_main *lst);
void	print_stacks(t_main *lst);
void	change_flag(t_main *lst, int counter);
void	last_three_elements_in_b(t_main *lst);
void	bonus_sa_sb(t_list **stck);
void	bonus_ss(t_list **sta, t_list **stb);
void	bonus_pa(t_list **sta, t_list **stb);
void	bonus_pb(t_list **sta, t_list **stb);
void	bonus_ra_rb(t_list **stck);
void	bonus_rr(t_list **sta, t_list **stb);
void	bonus_rra_rrb(t_list **stck);
void	bonus_rrr(t_list **sta, t_list **stb);
void	already_sorted_check(int *nums, int amount);
void	digit_check(char *str);
void	four_elements_ver_two(t_list **sta);
void	last_three_elements_in_b(t_main *lst);

#endif