/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:43:03 by asasada           #+#    #+#             */
/*   Updated: 2022/02/08 22:14:13 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rev_str(char *str)
{
	char	tmp;
	int		i;
	int		len;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static int	num_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	str = (char *)ft_calloc(num_len(n) + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[num_len(n) - 1] = '-';
	i = 0;
	while (n != 0)
	{
		str[i] = '0' + ft_abs(n % 10);
		i++;
		n /= 10;
	}
	rev_str(str);
	return (str);
}
/*
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(123));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(10));
	printf("%s\n", ft_itoa(1010100));
	printf("%s\n", ft_itoa(-100));
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(INT_MIN));
	return (0);
}
*/