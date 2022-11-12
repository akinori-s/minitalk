/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:18:06 by asasada           #+#    #+#             */
/*   Updated: 2022/02/10 21:18:06 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
/*
#include <stdio.h>

void	drop(void *content)
{
	printf("---\n");
	printf("drop: %s\n", (char *)content);
	printf("drop: %p\n", content);
	free(content);
	content = NULL;
	printf("drop: %p\n", content);
}

int	main(void)
{
	t_list	**list;
	// t_list	*elem1;
	// t_list	*elem2;
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = ft_calloc(10, sizeof(char));
	ft_strlcpy(str1, "asdf1", 10);
	str2 = ft_calloc(10, sizeof(char));
	ft_strlcpy(str2, "asdf2", 10);
	str3 = ft_calloc(10, sizeof(char));
	ft_strlcpy(str3, "asdf3", 10);

	// elem1 = ft_lstnew(str1);
	// list = &elem1;
	list = NULL;

	ft_lstadd_back(list, ft_lstnew(str2));
	// ft_lstadd_back(list, ft_lstnew(str3));

	// elem2 = ft_lstlast(*list);
	// printf("%p\n", (*list)->next);
	// printf("%p\n", (*list)->next->next);
	// printf("%p\n", (*list)->next->next->next);
	// printf("%p\n", elem2);
	ft_lstclear(list, &drop);
	// printf("%p\n", (*list)->next);
	// printf("%s\n", (char *)(*list)->content);
	// printf("%p\n", (*list)->next->next);
	// printf("%s\n", (char *)(*list)->next->content);
	// printf("%p\n", (*list)->next->next->next);
	// printf("%s\n", (char *)(*list)->next->next->content);
	// printf("%p\n", elem2);
	// printf("%p\n", elem2->next);
	// printf("%s\n", (char *)elem2->content);

	return (0);
}
*/