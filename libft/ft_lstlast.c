/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:23:56 by asasada           #+#    #+#             */
/*   Updated: 2022/02/10 14:23:56 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	**list;
	t_list	*elem1;
	t_list	*elem2;

	elem1 = ft_lstnew("asdf1");
	list = &elem1;
	elem2 = ft_lstnew("asdf2");

	printf("%d\n", ft_lstsize(*list));
	printf("%s\n", (char *)ft_lstlast(*list)->content);
	ft_lstadd_front(list, elem2);
	printf("%d\n", ft_lstsize(*list));
	printf("%s\n", (char *)ft_lstlast(*list)->content);
	ft_lstadd_front(list, ft_lstnew("asdf3"));
	printf("%d\n", ft_lstsize(*list));
	printf("%s\n", (char *)ft_lstlast(*list)->content);

	return (0);
}
*/