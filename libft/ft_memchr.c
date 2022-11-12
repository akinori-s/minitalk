/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:57:13 by asasada           #+#    #+#             */
/*   Updated: 2022/02/12 20:03:38 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((unsigned char *)(s + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[20] = "asdfjkl;";
	// char*	ptr = NULL;

	printf("----------Expected Output----------\n");
	printf("%p\n", memchr(s1, 'd', 0));
	printf("%p\n", memchr(s1, 'd', 5));
	printf("%p\n", memchr(s1, 'd', 20));
	printf("%p\n", memchr(s1, 'o', 20));
	// printf("%p\n", memchr(ptr, 'd', 5));		// seg fault
	printf("%p\n", memchr(s1, 'd', -1));
	printf("%p\n", memchr(s1, 'o', -1));


	printf("----------Actual Output----------\n");
	printf("%p\n", ft_memchr(s1, 'd', 0));
	printf("%p\n", ft_memchr(s1, 'd', 5));
	printf("%p\n", ft_memchr(s1, 'd', 20));
	printf("%p\n", ft_memchr(s1, 'o', 20));
	// printf("%p\n", ft_memchr(ptr, 'd', 5));		// seg fault
	printf("%p\n", ft_memchr(s1, 'd', -1));
	printf("%p\n", ft_memchr(s1, 'o', -1));
	return (0);
}
*/
