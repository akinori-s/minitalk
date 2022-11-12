/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:26:14 by asasada           #+#    #+#             */
/*   Updated: 2022/02/12 20:08:08 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char*s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0' && \
		(unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "ABC";
	// char*	ptr = NULL;

	printf("----------Expected Output----------\n");
	printf("ABC: ABD   = %d\n", strncmp(str, "ABD", 2));
	printf("ABC: ABC   = %d\n", strncmp(str, "ABC", 2));
	printf("ABC: AAA   = %d\n", strncmp(str, "AAA", 2));
	printf("ABC: ABCD  = %d\n", strncmp(str, "ABCD", 2));
	printf("ABC: AB    = %d\n", strncmp(str, "AB", 2));
	printf("ABC: B     = %d\n", strncmp(str, "B", 2));
	printf("ABC: A     = %d\n", strncmp(str, "A", 2));
	// printf("ABC: NULL     = %d\n", strncmp(str, ptr, 2));	// seg fault
	// printf("NULL: A     = %d\n", strncmp(ptr, "A", 2));	// seg fault
	// printf("NULL: NULL     = %d\n", strncmp(ptr, ptr, 2));	// seg fault

	printf("----------Actual Output----------\n");
	printf("ABC: ABD   = %d\n", ft_strncmp(str, "ABD", 2));
	printf("ABC: ABC   = %d\n", ft_strncmp(str, "ABC", 2));
	printf("ABC: AAA   = %d\n", ft_strncmp(str, "AAA", 2));
	printf("ABC: ABCD  = %d\n", ft_strncmp(str, "ABCD", 2));
	printf("ABC: AB    = %d\n", ft_strncmp(str, "AB", 2));
	printf("ABC: B     = %d\n", ft_strncmp(str, "B", 2));
	printf("ABC: A     = %d\n", ft_strncmp(str, "A", 2));
	// printf("ABC: NULL     = %d\n", ft_strncmp(str, ptr, 2));	// seg fault
	// printf("NULL: A     = %d\n", ft_strncmp(ptr, "A", 2));	// seg fault
	// printf("NULL: NULL     = %d\n", ft_strncmp(ptr, ptr, 2));	// seg fault
	return (0);
}
*/
