/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:18:53 by asasada           #+#    #+#             */
/*   Updated: 2022/02/11 23:30:23 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 1)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	if (s[i] == (char)c)
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
	printf("%s\n", strrchr("asdf", 's'));
	printf("%s\n", strrchr("asdfs", 's'));
	// printf("%s\n", strrchr("asdf", 'g'));	// seg fault
	printf("%s\n", strrchr("asdf", 'a'));
	// printf("%s\n", strrchr("", 'a'));		// seg fault
	// printf("%s\n", strrchr(ptr, 'a'));		// seg fault

	printf("----------Actual Output----------\n");
	printf("%s\n", ft_strrchr("asdf", 's'));
	printf("%s\n", ft_strrchr("asdfs", 's'));
	// printf("%s\n", ft_strrchr("asdf", 'g'));		// seg fault
	printf("%s\n", ft_strrchr("asdf", 'a'));
	// printf("%s\n", ft_strrchr("", 'a'));		// seg fault
	// printf("%s\n", ft_strrchr(ptr, 'a'));		// seg fault
	return (0);
}
*/