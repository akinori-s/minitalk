/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:34:12 by asasada           #+#    #+#             */
/*   Updated: 2022/02/15 10:16:27 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	i;

	str = malloc((ft_strlen(src) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "42";
	char	str2[] = "42 is the answer to the universe.";
	char	str3[] = "42tokyo";
	char	str4[] = "";
	char	str5[] = "abc";
	char	*str6 = NULL;

	str5[3] = 'd';

	printf("----------Original String----------\n");
	printf("ptr: %p, str1: %s\n", str1, str1);
	printf("ptr: %p, str2: %s\n", str2, str2);
	printf("ptr: %p, str3: %s\n", str3, str3);
	printf("ptr: %p, str4: %s\n", str4, str4);
	printf("ptr: %p, str5: %s\n", str5, str5);
	printf("----------Expected Output----------\n");
	printf("ptr: %p, str1: %s\n", strdup(str1), strdup(str1));
	printf("ptr: %p, str2: %s\n", strdup(str2), strdup(str2));
	printf("ptr: %p, str3: %s\n", strdup(str3), strdup(str3));
	printf("ptr: %p, str4: %s\n", strdup(str4), strdup(str4));
	printf("ptr: %p, str5: %s\n", strdup(str5), strdup(str5));
	// printf("ptr: %p, str5: %s\n", strdup(str6), strdup(str6));	// seg fault
	printf("-----------Actual Output-----------\n");
	printf("ptr: %p, str1: %s\n", ft_strdup(str1), ft_strdup(str1));
	printf("ptr: %p, str2: %s\n", ft_strdup(str2), ft_strdup(str2));
	printf("ptr: %p, str3: %s\n", ft_strdup(str3), ft_strdup(str3));
	printf("ptr: %p, str4: %s\n", ft_strdup(str4), ft_strdup(str4));
	printf("ptr: %p, str5: %s\n", ft_strdup(str5), ft_strdup(str5));
	// printf("ptr: %p, str5: %s\n", ft_strdup(str6), ft_strdup(str6));//segfault
	return (0);
}
*/