/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:24:27 by asasada           #+#    #+#             */
/*   Updated: 2022/02/09 21:00:02 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*elem;
	elem = ft_lstnew("asdf");
	printf("%s\n", elem->content);
	printf("%p\n", elem->next);
	return (0);
}
*/