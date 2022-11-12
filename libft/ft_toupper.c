/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:50:59 by asasada           #+#    #+#             */
/*   Updated: 2022/01/05 20:52:42 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_toupper('a'));
	printf("%d\n", ft_toupper('A'));
	printf("%d\n", ft_toupper('1'));
	return (0);
}
*/
