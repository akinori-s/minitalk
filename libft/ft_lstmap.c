/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:41:37 by asasada           #+#    #+#             */
/*   Updated: 2022/02/10 21:41:37 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	if (!f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, tmp);
		lst = lst->next;
	}
	return (new_list);
}
/*
#include <stdio.h>

void	*show(void *content)
{
	printf("---\n");
	printf("show: %s\n", (char *)content);
	printf("show: %p\n", content);
	ft_putendl_fd((char *)content, 1);
	return (content);
}

void    show2(void *content)
{
	printf("---\n");
	printf("show2: %s\n", (char *)content);
	printf("show2: %p\n", content);
	ft_putendl_fd((char *)content, 1);
}

void    drop(void *content)
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
	t_list	*list2;
	t_list	*elem1;
	char    *str1;
	char    *str2;
	char    *str3;

	str1 = ft_calloc(10, sizeof(char));
	ft_strlcpy(str1, "asdf1", 10);
	str2 = ft_calloc(10, sizeof(char));
	ft_strlcpy(str2, "asdf2", 10);
	str3 = ft_calloc(10, sizeof(char));
	ft_strlcpy(str3, "asdf3", 10);

	elem1 = ft_lstnew(str1);
	list = &elem1;

	ft_lstadd_back(list, ft_lstnew(str2));
	ft_lstadd_back(list, ft_lstnew(str3));

	ft_lstiter(*list, &show2);
	list2 = ft_lstmap(*list, &show, &drop);

	ft_lstiter(list2, &show2);

	list2 = ft_lstlast(NULL);

	elem1 = NULL;
	list2 = ft_lstmap(elem1, &show, &drop);


	return (0);
}
*/