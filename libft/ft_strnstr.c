/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:55:13 by asasada           #+#    #+#             */
/*   Updated: 2022/02/12 21:27:54 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_is_match(char *hay, char *needle);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_len;
	size_t	needle_len;
	size_t	i;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	if (haystack)
		haystack_len = ft_strlen(haystack);
	else
		haystack_len = 0;
	if (needle_len > haystack_len || needle_len > len)
		return (NULL);
	i = 0;
	while (i < (haystack_len - needle_len + 1) && i < (len - needle_len + 1))
	{
		if (str_is_match((char *)haystack + i, (char *)needle) == 1)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

static int	str_is_match(char *hay, char *needle)
{
	while (*needle != '\0')
	{
		if (*hay != *needle)
			return (0);
		hay++;
		needle++;
	}
	return (1);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	s1[] = "abcddefghijklmn";
	char	s2[] = "defgh";
	char	s3[] = "xyz";
	char	s4[] = "abcddefghijklmnopqr";
	char	s5[] = "";
	char	s6[] = "cdd";
	char	*sp1;
	char	*sp2;

	printf("----------Expected Output----------\n");
	sp1 = strnstr(s1, s2, 0);
	printf("no match : %s\n", sp1);
	sp1 = strnstr(s1, s2, 3);
	printf("no match : %s\n", sp1);
	sp1 = strnstr(s1, s2, 4);
	printf("no match : %s\n", sp1);
	sp1 = strnstr(s1, s2, 5);
	printf("no match : %s\n", sp1);
	sp1 = strnstr(s1, s2, 12);
	printf("match : %s\n", sp1);
	sp1 = strnstr(s1, s2, -1);
	printf("match : %s\n", sp1);
	sp1 = strnstr(s1, s3, 3);
	printf("no match : %s\n", sp1);
	sp1 = strnstr(s1, s4, 5);
	printf("len(needle) > len(haystack): %s\n", sp1);
	sp1 = strnstr(s1, s5, 2);
	printf("empty string : %s\n", sp1);
	sp1 = strnstr(s1, s6, 5);
	printf("match : %s\n", sp1);
	// sp1 = strnstr(NULL, s2, 10);		// seg fault
	// printf("%s\n", sp1);
	sp1 = strnstr(NULL, s2, 0);
	printf("%s\n", sp1);
	sp1 = strnstr(((void *)0), s2, 0);
	printf("%s\n", sp1);
	// sp1 = strnstr(s1, NULL, 10);		// seg fault
	// printf("%s\n", sp1);
	// sp1 = strnstr(s1, NULL, 0);			// seg fault
	// printf("%s\n", sp1);
	// sp1 = strnstr(NULL, NULL, 10);		// seg fault
	// printf("%s\n", sp1);
	sp1 = strnstr(NULL, "", 3);
	printf("%s\n", sp1);
	sp1 = strnstr(NULL, "", 0);
	printf("%s\n", sp1);
	printf("----------Actual Output----------\n");
	sp2 = ft_strnstr(s1, s2, 0);
	printf("no match : %s\n", sp2);
	sp2 = ft_strnstr(s1, s2, 3);
	printf("no match : %s\n", sp2);
	sp2 = ft_strnstr(s1, s2, 4);
	printf("no match : %s\n", sp2);
	sp2 = ft_strnstr(s1, s2, 5);
	printf("no match : %s\n", sp2);
	sp2 = ft_strnstr(s1, s2, 12);
	printf("match : %s\n", sp2);
	sp2 = ft_strnstr(s1, s2, -1);
	printf("match : %s\n", sp2);
	sp2 = ft_strnstr(s1, s3, 3);
	printf("no match : %s\n", sp2);
	sp2 = ft_strnstr(s1, s4, 5);
	printf("len(needle) > len(haystack): %s\n", sp2);
	sp2 = ft_strnstr(s1, s5, 2);
	printf("empty string : %s\n", sp2);
	sp2 = ft_strnstr(s1, s6, 5);
	printf("match : %s\n", sp2);
	// sp2 = ft_strnstr(NULL, s2, 10);		// seg fault
	// printf("%s\n", sp2);
	sp2 = ft_strnstr(((void *)0), s2, 0);
	printf("%s\n", sp2);
	sp2 = ft_strnstr(NULL, s2, 0);
	printf("%s\n", sp2);
	// sp2 = ft_strnstr(s1, NULL, 10);		// seg fault
	// printf("%s\n", sp2);
	// sp2 = ft_strnstr(s1, NULL, 0);			// seg fault
	// printf("%s\n", sp2);
	// sp2 = ft_strnstr(NULL, NULL, 10);		// seg fault
	// printf("%s\n", sp2);
	sp2 = ft_strnstr(NULL, "", 3);
	printf("%s\n", sp2);
	sp2 = ft_strnstr(NULL, "", 0);
	printf("%s\n", sp2);
	return 0;
}
*/