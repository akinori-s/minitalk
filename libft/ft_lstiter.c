/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:36:30 by asasada           #+#    #+#             */
/*   Updated: 2022/02/10 21:36:30 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>

void	show(void *content)
{
	printf("---\n");
	printf("show: %s\n", (char *)content);
	printf("show: %p\n", content);
	ft_putendl_fd((char *)content, 1);
}

int	main(void)
{
	t_list	**list;
	t_list	*elem1;
	char	*str1;
	char	*str2;
	char	*str3;

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

	ft_lstiter(*list, &show);

	return (0);
}
*/