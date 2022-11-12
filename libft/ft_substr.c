/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:05:21 by asasada           #+#    #+#             */
/*   Updated: 2022/02/17 20:59:11 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*ptr;
	size_t	substr_len;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		ptr = ft_strdup("");
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (start + len > ft_strlen(s))
		substr_len = ft_strlen(s) - start;
	else
		substr_len = len;
	ptr = malloc(sizeof(char) * substr_len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, substr_len + 1);
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "abcdefg";
	char	*ptr;
	ptr = ft_substr(s1, 1, 3);
	printf("%s\n", s1);
	printf("%s\n", ptr);
	ptr = ft_substr(s1, 0, 3);
	printf("%s\n", s1);
	printf("%s\n", ptr);
	ptr = ft_substr(s1, 0, 300);
	printf("%s\n", s1);
	printf("%s\n", ptr);
	ptr = ft_substr(NULL, 0, 300);		// seg fault
	printf("%s\n", s1);
	printf("%s\n", ptr);
	return (0);
}
*/