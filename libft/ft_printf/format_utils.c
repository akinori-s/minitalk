/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:15:29 by asasada           #+#    #+#             */
/*   Updated: 2022/09/05 22:15:29 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "info_controls.h"
#include "libft.h"

#define IS_ERROR -1

int	printf_write(const char *str, size_t n, t_info *info)
{
	if (n == 0)
		return (0);
	if (info->print_len + n > (size_t)INT_MAX)
		return (IS_ERROR);
	if (write(1, str, n) == IS_ERROR)
		return (IS_ERROR);
	info->print_len += n;
	return (0);
}

char	*make_padding(size_t len, char c)
{
	char	*str;

	if (len == 0)
		return (NULL);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	ft_memset(str, c, len);
	return (str);
}

int	put_padding(t_info *info, int pre_pad_len, bool is_prefix)
{
	char	*pad;
	int		pad_len;
	int		ret;

	if (pre_pad_len >= info->width
		|| info->zero_pad == true
		|| is_prefix == info->left_align)
		return (0);
	pad_len = info->width - pre_pad_len;
	pad = make_padding(pad_len, ' ');
	if (pad == NULL)
		return (IS_ERROR);
	ret = printf_write(pad, pad_len, info);
	free(pad);
	return (ret);
}

int	put_zero_pad(t_info *info, int pre_pad_len)
{
	char	*pad;
	int		pad_len;
	int		ret;

	if (info->zero_pad == false
		|| pre_pad_len >= info->width)
		return (0);
	pad_len = info->width - pre_pad_len;
	pad = make_padding(pad_len, '0');
	if (pad == NULL)
		return (IS_ERROR);
	ret = printf_write(pad, pad_len, info);
	free(pad);
	return (ret);
}

int	put_precision_zero(t_info *info, int strlen, bool is_neg)
{
	char	*pad;
	int		pad_len;
	int		ret;

	if (info->preci_flag == false
		|| strlen - is_neg >= info->preci)
		return (0);
	pad_len = info->preci - (strlen - is_neg);
	if (pad_len < 0)
		return (0);
	pad = make_padding(pad_len, '0');
	if (pad == NULL)
		return (IS_ERROR);
	ret = printf_write(pad, pad_len, info);
	free(pad);
	return (ret);
}
