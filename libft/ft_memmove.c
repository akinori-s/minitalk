/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:32:38 by asasada           #+#    #+#             */
/*   Updated: 2022/02/12 21:29:01 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = len;
		while (i >= 1)
		{
			*(char *)(dst + i - 1) = *(char *)(src + i - 1);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s1[20] = "0123456789";
	char	s2[20] = "abcdefg";
	char	t1[20] = "0123456789";
	char	t2[20] = "abcdefg";

	printf("-----Expected Output-----\n");
	memmove(s2, s1, 0);
	printf("%s %s\n", s1, s2);
	memmove(s2, s1, 1);
	printf("%s %s\n", s1, s2);
	memmove(s1, s2, 1);
	printf("%s %s\n", s1, s2);
	// memmove(s2, s1, -1);			//compile error
	// printf("%s %s\n", s1, s2);
	// memmove(NULL, s1, 1);			//compile error
	// printf("%s %s\n", s1, s2);
	// memmove(s2, NULL, 1);			//compile error
	// printf("%s %s\n", s1, s2);
	// memmove(NULL, NULL, 1);			//compile error
	// printf("%s %s\n", s1, s2);
	memmove(NULL, NULL, 5);			//compile error
	printf("%s %s\n", s1, s2);
	memmove(s2, s1, 20);
	printf("%s %s\n", s1, s2);

	printf("------Actual Output------\n");
	ft_memmove(t2, t1, 0);
	printf("%s %s\n", t1, t2);
	ft_memmove(t2, t1, 1);
	printf("%s %s\n", t1, t2);
	ft_memmove(t1, t2, 1);
	printf("%s %s\n", t1, t2);
	// ft_memmove(t2, t1, -1);			//runs indefinitely with underflowed value?
	// printf("%s %s\n", t1, t2);
	// ft_memmove(NULL, t1, 1);			//seg fault
	// printf("%s %s\n", t1, t2);
	// ft_memmove(t2, NULL, 1);			//seg fault
	// printf("%s %s\n", t1, t2);
	// ft_memmove(NULL, NULL, 1);			//seg fault
	// printf("%s %s\n", t1, t2);
	ft_memmove(t2, t1, 20);
	printf("%s %s\n", t1, t2);

	return (0);
}
 */