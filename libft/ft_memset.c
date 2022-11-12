/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:26:21 by asasada           #+#    #+#             */
/*   Updated: 2022/01/18 21:15:58 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(char *)(b + i) = (char)c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>
#include <string.h>
#include <limits.h>
int	main(void)
{
	char	s1[20] = "0123456789";
	char	s2[5] = "";
	char	*s3 = NULL;

	printf("-----Expected Output-----\n");
	memset(s1, 70, 5);
	printf("%s\n", s1);
	memset(s2, 70, 5);
	printf("%s\n", s2);
	//memset(s3, 70, 5);		//segfault
	//printf("%s\n", s3);
	memset(s1, INT_MAX, 1);
	printf("%s\n", s1);
	//memset(s1, INT_MIN, 1);		//segfault
	//printf("%s\n", s1);
	//memset(s1, 70, 0);			//compile error
	//printf("%s\n", s1);
	printf("------Actual Output------\n");
	ft_memset(s1, 70, 5);
	printf("%s\n", s1);
	ft_memset(s2, 70, 5);
	printf("%s\n", s2);
	//ft_memset(s3, 70, 5);			//segfault
	//printf("%s\n", s3);
	ft_memset(s1, INT_MAX, 1);
	printf("%s\n", s1);
	ft_memset(s1, INT_MIN, 1);
	printf("%s %lu %lu\n", s1, strlen(s1), strlen(s1 + 1));
	ft_memset(s1, 70, 0);
	printf("%s %lu %lu\n", s1, strlen(s1), strlen(s1 + 1));
	if (s3 == NULL)
		return (0);
	return (0);
}
*/
