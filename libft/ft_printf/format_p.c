/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:38:32 by asasada           #+#    #+#             */
/*   Updated: 2022/09/05 21:38:32 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_controls.h"
#include "format_utils.h"
#include "libft.h"

int	count_ullong_digits_in_base(unsigned long long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= base;
	}
	return (count);
}

char	*ullong_to_str(unsigned long long n, int base)
{
	char	*str;
	int		len;

	len = count_ullong_digits_in_base(n, base);
	str = malloc((len + 1) * sizeof(char));
	if (str != NULL)
	{
		str[len] = '\0';
		if (n == 0)
			str[0] = '0';
		while (n > 0)
		{
			if (n % base >= 10)
				str[len - 1] = n % base - 10 + 'a';
			else
				str[len - 1] = n % base + '0';
			n /= base;
			len--;
		}
	}
	return (str);
}

int	put_p(t_info *info, unsigned long long ptr)
{
	int		pre_pad_len;

	if (ptr == 0)
		info->tmp = ft_strdup("0");
	else
		info->tmp = ullong_to_str(ptr, 16);
	if (info->tmp == NULL)
		return (IS_ERROR);
	pre_pad_len = ft_strlen(info->tmp) + 2;
	if (put_padding(info, pre_pad_len, true))
		return (IS_ERROR);
	if (printf_write("0x", 2, info))
		return (IS_ERROR);
	if (printf_write(info->tmp, pre_pad_len - 2, info))
		return (IS_ERROR);
	if (put_padding(info, pre_pad_len, false))
		return (IS_ERROR);
	return (0);
}
