/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:14:58 by asasada           #+#    #+#             */
/*   Updated: 2022/02/17 20:50:14 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
int	main(void)
{
	char	s1[20] = "0123456789";
	char	s2[20] = "abcdefg";
	char	*ptr = NULL;
	char	*ptr2 = NULL;
	char	n1[1] = "";
	char	n2[1] = "";

	printf("-----Expected Output-----\n");
	memcpy(s2, s1, 1);
	printf("%s %s\n", s1, s2);
	memcpy(s2, s1, 0);
	printf("%s %s\n", s1, s2);
	//memcpy(s2, s1, -1);		//compile error: size always overflows
	//printf("%s %s\n", s1, s2);
	//memcpy(NULL, s1, 1);		//segfault
	//printf("%s %s\n", s1, s2);
	//memcpy(s2, NULL, 1);		//segfault
	//printf("%s %s\n", s1, s2);
	memcpy(ptr, ptr2, 1);
	printf("%s %s %p\n", s1, s2, memcpy(s2, s1, 1));
	memcpy(n1, n2, 1);
	printf("%s %s %p\n", s1, s2, memcpy(s2, s1, 1));
	printf("------Actual Output------\n");
	ft_memcpy(s2, s1, 1);
	printf("%s %s\n", s1, s2);
	ft_memcpy(s2, s1, 0);
	printf("%s %s\n", s1, s2);
	//ft_memcpy(s2, s1, -1);		//segfault
	//printf("%s %s\n", s1, s2);
	//ft_memcpy(NULL, s1, 1);		//segfault
	//printf("%s %s\n", s1, s2);
	//ft_memcpy(s2, NULL, 1);		//segfault
	//printf("%s %s\n", s1, s2);
	ft_memcpy(NULL, NULL, 1);
	printf("%s %s %p\n", s1, s2, ft_memcpy(s2, s1, 1));
	ft_memcpy(n1, n2, 1);
	printf("%s %s %p\n", s1, s2, ft_memcpy(s2, s1, 1));
	return (0);
}
*/