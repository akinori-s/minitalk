/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:26:14 by asasada           #+#    #+#             */
/*   Updated: 2022/02/17 20:44:48 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	checker;

	checker = count * size;
	if (checker / size != count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	void	*ptr;

	ptr = malloc(0);
	printf("%p\n", ptr);
	// ptr = malloc(SIZE_MAX);
	// printf("%p\n", ptr);
	printf("----------Expected Output----------\n");
	ptr = calloc(0, 12);
	printf("%p\n", ptr);
	ptr = calloc(12, 0);
	printf("%p\n", ptr);
	// ptr = calloc(SIZE_MAX, 1);
	// printf("%p\n", ptr);
	// ptr = calloc(1, SIZE_MAX - 2);
	// printf("%p\n", ptr);
	printf("----------Actual Output----------\n");
	ptr = ft_calloc(0, 12);
	printf("%p\n", ptr);
	ptr = ft_calloc(12, 0);
	printf("%p\n", ptr);

	// void	*ptr;

	// printf("%ld\n", sizeof(int));
	// ptr = ft_calloc(10, sizeof(int));
	// printf("%ld\n", sizeof(*ptr));
	// *(int *)(ptr + 10) = 20;
	// *(char *)(ptr + 0) = 'A';
	// *(char *)(ptr + 1) = 'A';
	// *(char *)(ptr + 2) = 'A';
	// *(char *)(ptr + 3) = 'A';
	// *(char *)(ptr + 4) = 'A';
	// *(char *)(ptr + 5) = 'A';
	// *(char *)(ptr + 6) = 'A';
	// *(char *)(ptr + 7) = 'A';
	// *(char *)(ptr + 8) = 'A';
	// *(char *)(ptr + 9) = 'A';
	// printf("%s\n", (char *)ptr);
	// printf("%s\n", (char *)(ptr + 10));
	// printf("%s\n", (char *)(ptr + 11));
	// printf("%s\n", (char *)(ptr + 12));
	// printf("%s\n", (char *)(ptr + 13));
	// printf("%d\n", *(int *)(ptr + 10));
	// printf("%ld\n", sizeof(ptr + 9));
	// printf("%ld\n", sizeof(ptr[9]));
	// printf("%ld\n", sizeof(ptr + 10));
	// printf("%ld\n", sizeof(ptr[10]));
	// printf("%ld\n", sizeof(ptr + 11));
	// printf("%ld\n", sizeof(ptr[11]));

	return (0);
}
*/