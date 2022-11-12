/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:06:12 by asasada           #+#    #+#             */
/*   Updated: 2022/01/18 20:24:30 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s1[] = "hello world";
	char	*s2 = NULL;

	printf("-----Library Output-----\n");
	printf("%lu\n", strlen(s1));
	printf("%lu\n", strlen(s2));
	printf("-------My Output--------\n");
	printf("%lu\n", ft_strlen(s1));
	printf("%lu\n", ft_strlen(s2));
	return (0);
}
*/
