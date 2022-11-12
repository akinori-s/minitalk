/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:58:54 by asasada           #+#    #+#             */
/*   Updated: 2022/05/07 21:22:16 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <limits.h>
#include <stddef.h>
#include "info_controls.h"
#include "libft.h"

#define IS_ERROR -1

static int		ascii_to_natural_int(const char *str);
static size_t	count_digits(const char *str);

int	read_width(t_info *info, const char *fmt, size_t *fmt_i, va_list *ap)
{
	if (fmt[*fmt_i] == '*')
	{
		info->width = va_arg(*ap, int);
		(*fmt_i) += 1;
		if (info->width == INT_MIN)
			return (IS_ERROR);
		else if (info->width < 0)
		{
			info->width *= -1;
			info->left_align = true;
		}
	}
	else if (ft_isdigit(fmt[*fmt_i]))
	{
		info->width = ascii_to_natural_int(fmt + *fmt_i);
		(*fmt_i) += count_digits(fmt + *fmt_i);
		if (info->width == IS_ERROR)
			return (IS_ERROR);
	}
	if (info->width == INT_MAX)
		return (IS_ERROR);
	return (0);
}

int	read_precision(t_info *info, const char *fmt, size_t *fmt_i, va_list *ap)
{
	if (fmt[*fmt_i] == '.')
	{
		(*fmt_i)++;
		info->preci_flag = true;
		if (fmt[*fmt_i] == '*')
		{
			info->preci = va_arg(*ap, int);
			(*fmt_i)++;
			if (info->preci < 0)
				info->preci_flag = false;
		}
		else if (ft_isdigit(fmt[*fmt_i]))
		{
			info->preci = ascii_to_natural_int(fmt + *fmt_i);
			(*fmt_i) += count_digits(fmt + *fmt_i);
			if (info->preci == IS_ERROR)
				return (IS_ERROR);
		}
	}
	if (info->preci == INT_MAX)
		return (IS_ERROR);
	return (0);
}

static int	ascii_to_natural_int(const char *str)
{
	size_t	num;
	size_t	i;

	num = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
		if (num > INT_MAX)
			return (IS_ERROR);
	}
	return (num);
}

static size_t	count_digits(const char *str)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}
