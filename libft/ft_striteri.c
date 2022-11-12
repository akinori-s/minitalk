/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:42:40 by asasada           #+#    #+#             */
/*   Updated: 2022/02/17 20:51:42 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(size_t, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, (s + i));
		i++;
	}
}
/*
#include <stdio.h>
static void	show_even(unsigned int i, char *s)
{
	if (i % 2 == 0)
		*s = '_';
}

int	main(void)
{
	char	str[] = "asdfjkl;";

	printf("%s\n", str);
	ft_striteri(str, &show_even);
	printf("%s\n", str);
	// printf("%s\n", str);
	// ft_striteri(NULL, &show_even);		// seg fault
	// printf("%s\n", str);
	// printf("%s\n", str);
	// ft_striteri(str, NULL);		// seg fault
	// printf("%s\n", str);
	// printf("%s\n", str);
	// ft_striteri(NULL, NULL);		// seg fault
	// printf("%s\n", str);
	return (0);
}
*/