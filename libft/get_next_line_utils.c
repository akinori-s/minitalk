/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:15:51 by asasada           #+#    #+#             */
/*   Updated: 2022/11/06 13:15:51 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
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

char	*gnl_strdup(const char *src)
{
	char	*str;
	size_t	i;

	if (!src)
		return (NULL);
	str = malloc((gnl_strlen((char *)src) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = gnl_strlen((char *)s1);
	s2_len = gnl_strlen((char *)s2);
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (gnl_strdup(s2));
	else if (!s2)
		return (gnl_strdup(s1));
	if (SIZE_MAX - s1_len < s2_len + 1)
		return (NULL);
	joined = malloc(s1_len + s2_len + 1);
	if (!joined)
		return (NULL);
	joined[s1_len + s2_len] = '\0';
	i = 0;
	while (*s1)
		joined[i++] = *s1++;
	while (*s2)
		joined[i++] = *s2++;
	return (joined);
}

char	*gnl_substr(char const *s, size_t start, size_t len)
{
	char	*ptr;
	size_t	substr_len;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > gnl_strlen((char *)s))
		return (gnl_strdup(""));
	if (start + len > gnl_strlen((char *)s))
		substr_len = gnl_strlen((char *)s) - start;
	else
		substr_len = len;
	ptr = malloc(substr_len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[start + i] && i < substr_len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
