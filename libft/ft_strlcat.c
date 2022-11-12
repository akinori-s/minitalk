/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 08:41:02 by asasada           #+#    #+#             */
/*   Updated: 2022/02/16 21:03:56 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	if (dst)
	{
		while (dst[i] != '\0' && i < dstsize)
			i++;
	}
	dst_len = i;
	dst += i;
	i = 0;
	if (dst_len < dstsize && dst)
	{
		while (i < dstsize - dst_len - 1 && src[i] != '\0' && dstsize != 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst_len + ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int	main(void)
{
	char	str1[20] = "ABC";
	char	str2[] = "12345";
	char	str3[20] = "ABC";
	char	str4[] = "12345";
	unsigned int	len1;
	unsigned int	len2;

	printf("----------Expected Output----------\n");
	len1 = strlcat(str1, str2, 1);
	printf("%s\n", str1);
	printf("%d\n", len1);
	len1 = strlcat(str1, str2, 3);
	printf("%s\n", str1);
	printf("%d\n", len1);
	len1 = strlcat(str1, str2, 4);
	printf("%s\n", str1);
	printf("%d\n", len1);
	len1 = strlcat(str1, str2, 5);
	printf("%s\n", str1);
	printf("%d\n", len1);
	len1 = strlcat(str1, str2, 10);
	printf("%s\n", str1);
	printf("%d\n", len1);
	len1 = strlcat(str1, "123456", 0);
	printf("%s\n", str1);
	printf("%d\n", len1);
	// len1 = strlcat(str1, "123456", -1);	// will always overflow cmpl error
	// printf("%s\n", str1);
	// printf("%d\n", len1);
	len1 = strlcat(NULL, "123456", 0);
	printf("%s\n", str1);
	printf("%d\n", len1);
	// len1 = strlcat(str1, NULL, 0);		// seg fault
	// printf("%s\n", str1);
	// printf("%d\n", len1);
	// len1 = strlcat(NULL, NULL, 0);			// seg fault
	// printf("%s\n", str1);
	// printf("%d\n", len1);
	len1 = strlcat('\0', "123456", 0);
	printf("%s\n", str1);
	printf("%d\n", len1);
	// len1 = strlcat(NULL, '\0', 0);		// seg fault
	// printf("%s\n", str1);
	// printf("%d\n", len1);
	// len1 = strlcat('\0', '\0', 1);		// seg fault
	// printf("%s\n", str1);
	// printf("%d\n", len1);

	printf("----------Actual Output----------\n");
	len2 = ft_strlcat(str3, str4, 1);
	printf("%s\n", str3);
	printf("%d\n", len2);
	len2 = ft_strlcat(str3, str4, 3);
	printf("%s\n", str3);
	printf("%d\n", len2);
	len2 = ft_strlcat(str3, str4, 4);
	printf("%s\n", str3);
	printf("%d\n", len2);
	len2 = ft_strlcat(str3, str4, 5);
	printf("%s\n", str3);
	printf("%d\n", len2);
	len2 = ft_strlcat(str3, str4, 10);
	printf("%s\n", str3);
	printf("%d\n", len2);
	len2 = ft_strlcat(str3, "123456", 0);
	printf("%s\n", str3);
	printf("%d\n", len2);
	// len2 = ft_strlcat(str3, "123456", -1);		// runs normally
	// printf("%s\n", str3);
	// printf("%d\n", len2);
	len2 = ft_strlcat(NULL, "123456", 0);
	printf("%s\n", str3);
	printf("%d\n", len2);
	// len2 = ft_strlcat(str3, NULL, 0);		// seg fault
	// printf("%s\n", str3);
	// printf("%d\n", len2);
	// len2 = ft_strlcat(NULL, NULL, 0);		// seg fault
	// printf("%s\n", str3);
	// printf("%d\n", len2);
	len1 = ft_strlcat('\0', "123456", 0);
	printf("%s\n", str1);
	printf("%d\n", len1);
	// len1 = ft_strlcat(NULL, '\0', 0);		// seg fault
	// printf("%s\n", str1);
	// printf("%d\n", len1);
	// len1 = ft_strlcat('\0', '\0', 1);		// seg fault
	// printf("%s\n", str1);
	// printf("%d\n", len1);
	return 0;
}
*/