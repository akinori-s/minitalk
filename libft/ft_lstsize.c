/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:03:05 by asasada           #+#    #+#             */
/*   Updated: 2022/02/10 14:03:05 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	count;

	if (!lst)
		return (0);
	count = 1;
	while (lst->next)
	{
		lst = lst->next;
		count++;
	}
	return (count);
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
	list = &elem1;
	elem2 = ft_lstnew("asdf2");

	printf("%d\n", ft_lstsize(*list));
	ft_lstadd_front(list, elem2);
	printf("%d\n", ft_lstsize(*list));
	ft_lstadd_front(list, ft_lstnew("asdf3"));
	printf("%d\n", ft_lstsize(*list));

	return (0);
}
*/