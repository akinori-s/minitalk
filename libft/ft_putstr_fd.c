/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:01:26 by asasada           #+#    #+#             */
/*   Updated: 2022/02/17 21:02:19 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;

	if (!s)
		return ;
	s_len = ft_strlen(s);
	while (s_len > INT_MAX)
	{
		write(fd, s, ft_strlen(s));
		s_len -= INT_MAX;
		s += INT_MAX;
	}
	write(fd, s, s_len);
}
/*
#include <stdio.h>
int	main(void)
{
	ft_putstr_fd("asdf", 1);
	printf("\n");
	ft_putstr_fd("", 1);
	printf("\n");
	ft_putstr_fd("\n", 1);
	printf("\n");
	// ft_putstr_fd(NULL, 1);	// seg fault
	// printf("\n");
	return (0);
}
*/