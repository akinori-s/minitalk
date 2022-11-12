/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:30:06 by asasada           #+#    #+#             */
/*   Updated: 2022/02/18 08:41:50 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strddup(char *src, char c)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len] != '\0' && src[len] != c)
		len++;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static	int	split_len(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count += 1;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	**freedom(char **ptr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = (char **)malloc((split_len(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			ptr[j] = ft_strddup((char *)(s + i), c);
			if (!ptr[j])
				return (freedom(ptr, j));
			i += ft_strlen(ptr[j++]);
		}
	}
	ptr[j] = NULL;
	return (ptr);
}
/*
#include <stdio.h>

int	show(char **ptr)
{
	int	i;

	printf("-----\n");
	if (!ptr)
		return (0);
	i = 0;
	while (ptr[i] != NULL)
	{
		printf("%d: %s\n", i, ptr[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	char	str1[] = "c c c c";
	char	charset = ' ';
	char	**p;

	p = ft_split(str1, charset);
	show(p);
	p = ft_split("   ", ' ');
	show(p);
	p = ft_split(str1, '0');
	show(p);
	// p = ft_split(NULL, '0');		// seg fault
	// show(p);

	return (0);
}
*/