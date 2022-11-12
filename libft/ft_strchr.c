/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:03:47 by asasada           #+#    #+#             */
/*   Updated: 2022/02/11 23:24:42 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	// char* 	ptr = NULL;

	printf("----------Expected Output----------\n");
	printf("%s\n", strchr("asdf", 's'));
	// printf("%s\n", strchr("asdf", 'g'));	// seg fault
	printf("%s\n", strchr("asdf", 'a'));
	// printf("%s\n", strchr("", 'a'));		// seg fault
	// printf("%s\n", strchr(ptr, 'a'));		// seg fault

	printf("----------Actual Output----------\n");
	printf("%s\n", ft_strchr("asdf", 's'));
	// printf("%s\n", ft_strchr("asdf", 'g'));		// seg fault
	printf("%s\n", ft_strchr("asdf", 'a'));
	// printf("%s\n", ft_strchr("", 'a'));		// seg fault
	// printf("%s\n", ft_strchr(ptr, 'a'));		// seg fault
	return (0);
}
*/
