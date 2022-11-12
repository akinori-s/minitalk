/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:09:02 by asasada           #+#    #+#             */
/*   Updated: 2022/02/02 10:58:10 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char*	ptr = NULL;

	printf("----------Expected Output----------\n");
	printf("%d\n", memcmp("asdf", "asdg", 0));
	printf("%d\n", memcmp("asdf", "asdg", 1));
	printf("%d\n", memcmp("asdf", "asdg", 5));
	printf("%d\n", memcmp("asdf", "asdg", 6));
	printf("%d\n", memcmp("asdf", "asdg", -1));
	// printf("%d\n", memcmp(ptr, "asdg", 1));			// seg fault
	// printf("%d\n", memcmp("asdf", ptr, 1));			// seg fault
	// printf("%d\n", memcmp(ptr, ptr, 1));				// seg fault

	printf("----------Actual Output----------\n");
	printf("%d\n", ft_memcmp("asdf", "asdg", 0));
	printf("%d\n", ft_memcmp("asdf", "asdg", 1));
	printf("%d\n", ft_memcmp("asdf", "asdg", 5));
	printf("%d\n", ft_memcmp("asdf", "asdg", 6));
	printf("%d\n", ft_memcmp("asdf", "asdg", -1));
	// printf("%d\n", ft_memcmp(ptr, "asdg", 1));		// seg fault
	// printf("%d\n", ft_memcmp("asdf", ptr, 1));		// seg fault
	// printf("%d\n", ft_memcmp(ptr, ptr, 1));			// seg fault

	return (0);
}
*/
