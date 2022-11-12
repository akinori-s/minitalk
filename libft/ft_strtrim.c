/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:45:20 by asasada           #+#    #+#             */
/*   Updated: 2022/02/15 10:47:05 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, (int)s1[i]) && i < s1_len)
		i++;
	j = s1_len - 1;
	if (i != s1_len)
	{
		while (ft_strchr(set, (int)s1[j]) && j >= 1)
			j--;
	}
	if (i > j)
		return (ft_substr(s1, i, 1));
	else
		return (ft_substr(s1, i, j - i + 1));
}
/*
#include <stdio.h>
int	main(void)
{
	char	s1[] = "aaabcbcbaaa";
	char	s2[] = "c";
	char	s3[] = "aaabababaaa";
	char	s4[] = "caaabababaaa";
	char	s5[] = "aaabababaaac";

	printf("%s\n", ft_strtrim(s1, "ab"));
	printf("%s\n", ft_strtrim(s2, "ab"));
	printf("%s\n", ft_strtrim(s3, "ab"));
	printf("%s\n", ft_strtrim(s3, ""));
	printf("%s\n", ft_strtrim(s4, "ab"));
	printf("%s\n", ft_strtrim(s5, "ab"));
	// printf("%s\n", ft_strtrim(NULL, "ab"));		// seg fault
	// printf("%s\n", ft_strtrim(s5, NULL));		// seg fault
	// printf("%s\n", ft_strtrim(NULL, NULL));		// seg fault
	return (0);
}
*/