/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:05:56 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/23 01:25:44 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new -> data = data;
	new -> next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
//	printf("lstlast%d\n", lst -> data);
	printf("%s\n", "5");
	while (lst)
	{
		if (!lst->next)
			return (lst);
		printf("%s\n", "6");
		lst = lst->next;
	}
	printf("%s\n", "7");
	return (lst);
}

void	ft_lstadd_back(t_list *lst, t_list *new)
{
// 	t_list	*p;

// 	if (!new)
// 		return ;
// 	printf("%s\n", "1");
// 	if (!*lst)
// 	{
// 		printf("%s\n", "2");
// 		*lst = new;
// 		printf("%s\n", "2");
// 		return ;
// 	}
// //	printf("lst data: %d\n", new -> data);
// 	printf("%s\n", "3");
// 	p = ft_lstlast(*lst);
// 	printf("%s\n", "4");
// //	printf("lst data: %d\n", new -> data);
// 	p -> next = new;

	t_list *ptr;

	ptr = lst;
	if (lst -> next == NULL)
		lst = new;
//	printf("%s\n", "4");
	else++
	{
		printf("%s\n", "3");
		while (ptr->next)
			ptr = ptr->next;
		printf("%s\n", "3");
		ptr->next = new;
	}
	printf("%s\n", "3");
	
}