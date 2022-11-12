/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:30:04 by asasada           #+#    #+#             */
/*   Updated: 2022/03/15 11:22:55 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(size_t, char))
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	str = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, (char)s[i]);
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
static char	char_index_mod(unsigned int i, char c)
{
	c = '0';
	return (c + i % 10);
}

int	main(void)
{
	printf("%s\n", ft_strmapi("asdf", &char_index_mod));
	printf("%s\n", ft_strmapi("asdfasdfasdf", &char_index_mod));
	// printf("%s\n", ft_strmapi(NULL, &char_index_mod));	// seg fault
	// printf("%s\n", ft_strmapi("asdfasdfasdf", NULL));		// seg fault
	// printf("%s\n", ft_strmapi(NULL, NULL));		// seg fault
	return (0);
}
*/