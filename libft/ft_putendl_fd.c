/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:41:43 by asasada           #+#    #+#             */
/*   Updated: 2022/02/12 21:21:34 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	nl;

	if (!s)
		return ;
	nl = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &nl, 1);
}
/*
#include <stdio.h>
int	main(void)
{
	ft_putendl_fd("asdf", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("jkl;", 1);
	// ft_putendl_fd(NULL, 1);		// seg fault
	return (0);
}
*/