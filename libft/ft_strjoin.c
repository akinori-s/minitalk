/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:37:26 by asasada           #+#    #+#             */
/*   Updated: 2022/10/05 23:23:32 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (SIZE_MAX - s1_len < s2_len + 1)
		return (NULL);
	joined = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, s1_len + 1);
	ft_strlcat(joined, s2, s1_len + s2_len + 1);
	return (joined);
}
/*
#include <stdio.h>
int	main(void)
{
	char	s1[] = "abc";
	char	s2[] = "def";
	char	*ptr;

	ptr = ft_strjoin(s1, s2);
	printf("%s\n", ptr);
	ptr = ft_strjoin(s1, "");
	printf("%s\n", ptr);
	ptr = ft_strjoin("", s2);
	printf("%s\n", ptr);
	ptr = ft_strjoin("", "");
	printf("%s\n", ptr);
	ptr = ft_strjoin("asdf", "asdf");
	printf("%s\n", ptr);
	// ptr = ft_strjoin(NULL, "asdf");		// seg fault
	// printf("%s\n", ptr);
	// ptr = ft_strjoin("asdf", NULL);		// seg fault
	// printf("%s\n", ptr);
	// ptr = ft_strjoin(NULL, NULL);		// seg fault
	// printf("%s\n", ptr);
	return (0);
}
*/