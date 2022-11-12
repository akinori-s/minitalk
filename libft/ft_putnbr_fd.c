/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:56:14 by asasada           #+#    #+#             */
/*   Updated: 2022/02/09 20:47:55 by asasada          ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	char	str[13];
	int		i;

	ft_bzero(str, 13);
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
	ft_putstr_fd(str, fd);
}
/*
#include <limits.h>
int	main(void)
{
	ft_putnbr_fd(0, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(INT_MAX, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(INT_MIN, 1);
	ft_putstr_fd("\n", 1);
	// ft_itoa_fd(0, 1);
	// ft_putstr_fd("\n", 1);
	// ft_itoa_fd(101000, 1);
	// ft_putstr_fd("\n", 1);
	// ft_itoa_fd(INT_MAX, 1);
	// ft_putstr_fd("\n", 1);
	// ft_itoa_fd(INT_MIN, 1);
	// ft_putstr_fd("\n", 1);
	return (0);
}
*/