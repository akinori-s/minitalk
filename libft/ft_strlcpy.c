/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:56:08 by asasada           #+#    #+#             */
/*   Updated: 2022/02/12 20:23:17 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize - 1 && src[i] != '\0' && dstsize != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	str1[20] = "asdf123456";
	char	str2[20] = "asdf123456";
	int		len1;
	int		len2;

	printf("----------Expected Output----------\n");
	len1 = strlcpy(str1, "ABC", 0);
	printf("%s\n", str1);
	printf("%d\n", len1);
	len1 = strlcpy(str1, "", 3);
	printf("%s\n", str1);
	printf("%d\n", len1);
	len1 = strlcpy(str1, "ABC", 3);
	printf("%s\n", str1);
	printf("%d\n", len1);
	len1 = strlcpy(str1, "ABC", 10);
	printf("%s\n", str1);
	printf("%d\n", len1);
	// len1 = strlcpy(str1, "ABC", -1);		// will always overflow
	// printf("%s\n", str1);
	// printf("%d\n", len1);
	// len1 = strlcpy(NULL, "ABC", 10);		// seg fault
	// printf("%s\n", str1);
	// printf("%d\n", len1);
	// len1 = strlcpy(str1, NULL, 10);		// seg fault
	// printf("%s\n", str1);
	// printf("%d\n", len1);
	// len1 = strlcpy(NULL, NULL, 10);		// seg fault
	// printf("%s\n", str1);
	// printf("%d\n", len1);

	printf("----------Actual Output----------\n");
	len2 = ft_strlcpy(str2, "ABC", 0);
	printf("%s\n", str2);
	printf("%d\n", len2);
	len2 = ft_strlcpy(str2, "", 3);
	printf("%s\n", str2);
	printf("%d\n", len2);
	len2 = ft_strlcpy(str2, "ABC", 3);
	printf("%s\n", str2);
	printf("%d\n", len2);
	len2 = ft_strlcpy(str2, "ABC", 10);
	printf("%s\n", str2);
	printf("%d\n", len2);
	len2 = ft_strlcpy(str2, "ABC", -1);			//runs normally
	printf("%s\n", str2);
	printf("%d\n", len2);
	// len2 = ft_strlcpy(NULL, "ABC", 10);		// seg fault
	// printf("%s\n", str2);
	// printf("%d\n", len2);
	// len2 = ft_strlcpy(str2, NULL, 10);		// seg fault
	// printf("%s\n", str2);
	// printf("%d\n", len2);
	// len2 = ft_strlcpy(NULL, NULL, 10);			// seg fault
	// printf("%s\n", str2);
	// printf("%d\n", len2);

	return 0;
}
*/