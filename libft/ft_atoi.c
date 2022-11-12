/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:52:03 by asasada           #+#    #+#             */
/*   Updated: 2022/02/13 19:11:34 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				m_count;
	unsigned long	n;

	n = 0;
	m_count = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			m_count = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = (n * 10) + (*str - '0');
		if (n > LONG_MAX && m_count == 1)
			return (-1);
		else if (n > (unsigned long)LONG_MAX + 1 && m_count == -1)
			return (0);
		str++;
	}
	return (((int)n) * m_count);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main()
{
	char	s1[] = "   \n\t\v\r  -123asdf45";
	char	s2[] = "+01234-789";
	char	s3[] = "-adf";
	char	s4[] = "";
	char	s5[] = "--+2147483647";
	char	s6[] = "  - 2147483648";
	char	s7[] = "  sdf--+-2147483648";
	char	s8[] = "  -1sdf+-2147483648";
	char	s9[] = "  -2147483648";
	char	s10[] = "  +2147483648";
	char	s11[] = "  +2147483647";
	char	s12[] = "  +2147483647123";
	// char	s13[] = "  +99999999999999999999999999";
	// char	s14[] = "-99999999999999999999999999";
	char	s13[] = "  +9999999999999999999999999";
	char	s14[] = "-9999999999999999999999999";
	// char*	ptr = NULL;

	printf("----------Expected Output----------\n");
	printf("%d\n", atoi(s1));
	printf("%d\n", atoi(s2));
	printf("%d\n", atoi(s3));
	printf("%d\n", atoi(s4));
	printf("%d\n", atoi(s5));
	printf("%d\n", atoi(s6));
	printf("%d\n", atoi(s7));
	printf("%d\n", atoi(s8));
	printf("%d\n", atoi(s9));
	printf("%d\n", atoi(s10));
	printf("%d\n", atoi(s11));
	printf("%d\n", atoi(s12));
	printf("%d\n", atoi(s13));
	printf("%d\n", atoi(s14));
	// printf("%d\n", atoi(ptr));		// seg fault
	printf("-------------strol-------------\n");
	printf("%d\n", (int)strtol(s1, (char **) NULL, 10));
	printf("%d\n", (int)strtol(s2, (char **) NULL, 10));
	printf("%d\n", (int)strtol(s3, (char **) NULL, 10));
	printf("%d\n", (int)strtol(s4, (char **) NULL, 10));
	printf("%d\n", (int)strtol(s5, (char **) NULL, 10));
	printf("%d\n", (int)strtol(s6, (char **) NULL, 10));
	printf("%d\n", (int)strtol(s7, (char **) NULL, 10));
	printf("%d\n", (int)strtol(s8, (char **) NULL, 10));
	printf("%d\n", (int)strtol(s9, (char **) NULL, 10));
	printf("%d\n", (int)strtol(s10, (char **) NULL, 10));
	printf("%d\n", (int)strtol(s11, (char **) NULL, 10));
	printf("%d\n", (int)strtol(s12, (char **) NULL, 10));
	printf("%d\n", (int)strtol(s13, (char **) NULL, 10));
	printf("%d\n", (int)strtol(s14, (char **) NULL, 10));
	// printf("%d\n", (int)strtol(ptr, (char **) NULL, 10));	// seg fault
	printf("----------Actual Output----------\n");
	printf("%d\n", ft_atoi(s1));
	printf("%d\n", ft_atoi(s2));
	printf("%d\n", ft_atoi(s3));
	printf("%d\n", ft_atoi(s4));
	printf("%d\n", ft_atoi(s5));
	printf("%d\n", ft_atoi(s6));
	printf("%d\n", ft_atoi(s7));
	printf("%d\n", ft_atoi(s8));
	printf("%d\n", ft_atoi(s9));
	printf("%d\n", ft_atoi(s10));
	printf("%d\n", ft_atoi(s11));
	printf("%d\n", ft_atoi(s12));
	printf("%d\n", ft_atoi(s13));
	printf("%d\n", ft_atoi(s14));
	// printf("%d\n", ft_atoi(ptr));		// seg fault
	return (0);
}
*/