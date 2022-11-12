/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:38:33 by asasada           #+#    #+#             */
/*   Updated: 2022/09/05 21:38:33 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_controls.h"
#include "format_utils.h"
#include "libft.h"

int	count_uint_digits_in_base(unsigned int n, int base)
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

char	*uint_to_str(unsigned int n, int base)
{
	char	*str;
	int		len;

	len = count_uint_digits_in_base(n, base);
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

void	set_default_uxx_preci(t_info *info)
{
	if (info->preci_flag == false)
	{
		info->preci_flag = true;
		info->preci = 1;
	}
}

int	pre_pad_len_u(t_info *info, int strlen)
{
	int	pre_pad_len;

	if (info->preci_flag == true && info->preci > strlen)
		pre_pad_len = info->preci;
	else
		pre_pad_len = strlen;
	return (pre_pad_len);
}

int	put_u(t_info *info, unsigned int num)
{
	int	pre_pad_len;
	int	strlen;

	set_default_uxx_preci(info);
	if (info->preci_flag == true && info->preci == 0 && num == 0)
		info->tmp = ft_strdup("");
	else
		info->tmp = uint_to_str(num, 10);
	if (info->tmp == NULL)
		return (IS_ERROR);
	strlen = ft_strlen(info->tmp);
	pre_pad_len = pre_pad_len_u(info, strlen);
	if (put_padding(info, pre_pad_len, true))
		return (IS_ERROR);
	if (put_zero_pad(info, pre_pad_len))
		return (IS_ERROR);
	if (put_precision_zero(info, strlen, false))
		return (IS_ERROR);
	if (printf_write(info->tmp, strlen, info))
		return (IS_ERROR);
	if (put_padding(info, pre_pad_len, false))
		return (IS_ERROR);
	return (0);
}
