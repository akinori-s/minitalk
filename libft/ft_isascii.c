/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:43:31 by asasada           #+#    #+#             */
/*   Updated: 2022/01/18 20:16:02 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("%d\n", ft_isascii('a'));
	printf("%d\n", ft_isascii('1'));
	return (0);
}
*/
