/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:20:59 by asasada           #+#    #+#             */
/*   Updated: 2022/02/17 20:45:41 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	s[20] = "0123456789";
	char	s1[20] = "0123456789";
	char	*s2 = NULL;

	printf("-----Expected Output-----\n");
	bzero(s, 1);
	printf("%s %lu\n", s, strlen(s + 1));
	//bzero(s, 0);		//compile error: size is 0
	//printf("%s\n", s);
	//bzero(s, -1);		//compile error: size overflow
	//printf("%s\n", s);
	//bzero(s2, 1);		//segfault
	//printf("%s\n", s2);
	printf("------Actual Output------\n");
	ft_bzero(s1, 1);
	printf("%s %lu\n", s1, strlen(s1 + 1));
	ft_bzero(s1, 0);
	printf("%s %lu\n", s1, strlen(s1 + 1));
	//ft_bzero(s1, -1);		//segfault
	//printf("%s %lu\n", s1, strlen(s1 + 1));
	//ft_bzero(s2, 1);		//segfault
	//printf("%s %lu\n", s2, strlen(s2 + 1));
	
	if (s2 == NULL)
		return (0);
	return (0);
}
*/
