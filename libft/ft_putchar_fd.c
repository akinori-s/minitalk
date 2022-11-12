/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:52:58 by asasada           #+#    #+#             */
/*   Updated: 2022/02/09 20:22:11 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	ft_putchar_fd('a', 0);
	ft_putchar_fd('a', 1);
	ft_putchar_fd('a', 2);
	ft_putchar_fd('\n', 2);
	return (0);
}
*/