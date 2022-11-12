/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:37:08 by asasada           #+#    #+#             */
/*   Updated: 2022/02/10 14:37:08 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	**list;
	t_list	*elem1;

	elem1 = ft_lstnew("asdf1");
	list = &elem1;

	printf("%d\n", ft_lstsize(*list));
	printf("%s\n", (char *)ft_lstlast(*list)->content);

	ft_lstadd_back(list, ft_lstnew("asdf2"));
	printf("%d\n", ft_lstsize(*list));
	printf("%s\n", (char *)ft_lstlast(*list)->content);

	ft_lstadd_back(list, ft_lstnew("asdf3"));
	printf("%d\n", ft_lstsize(*list));
	printf("%s\n", (char *)ft_lstlast(*list)->content);

	return (0);
}
*/