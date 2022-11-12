/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:58:02 by asasada           #+#    #+#             */
/*   Updated: 2022/02/17 21:09:09 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		ft_lstlast(new)->next = *lst;
		*lst = new;
	}
}
/*
#include <stdio.h>
#include <stdio.h>

int	main(void)
{
	t_list	**list;
	t_list	*elem1;
	t_list	*elem2;

	elem1 = ft_lstnew("asdf1");
	elem2 = ft_lstnew("asdf2");

	list = &elem1;

	printf("%s\n", (char *)(*list)->content);
	printf("---\n");
	ft_lstadd_front(list, elem2);
	printf("%s\n", (char *)(*list)->content);
	printf("%s\n", (char *)(*list)->next->content);
	// printf("%s\n", (char *)(elem2)->content);

	return (0);
}
*/