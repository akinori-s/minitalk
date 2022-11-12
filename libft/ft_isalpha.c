/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:08:13 by asasada           #+#    #+#             */
/*   Updated: 2022/01/18 20:14:43 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("-----Library Output-----\n");
	printf("%d\n", isalpha('a'));
	printf("%d\n", isalpha('1'));
	printf("--------My Output-------\n");
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isalpha('1'));
	return (0);
}
*/
