/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di.c                                        :+:      :+:    :+:   */
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

int	pre_pad_len_d(t_info *info, char *str, bool is_neg)
{
	int	pre_pad_len;
	int	strlen;

	strlen = ft_strlen(str) - is_neg;
	if (info->preci_flag == true && info->preci > strlen)
		pre_pad_len = info->preci;
	else
		pre_pad_len = strlen;
	if (info->plus || info->space || is_neg)
		pre_pad_len += 1;
	return (pre_pad_len);
}

int	put_plus_minus_space(t_info *info, bool is_neg)
{
	int		ret;

	if (is_neg == true)
		ret = printf_write("-", 1, info);
	else if (info->plus == true)
		ret = printf_write("+", 1, info);
	else if (info->space == true)
		ret = printf_write(" ", 1, info);
	else
		ret = 0;
	return (ret);
}

void	set_default_d_flag(t_info *info)
{
	if (info->preci_flag == false)
	{
		info->preci_flag = true;
		info->preci = 1;
	}
}

int	put_di(t_info *info, int num)
{
	int		pre_pad_len;
	bool	is_neg;

	set_default_d_flag(info);
	is_neg = (num < 0);
	if (info->preci == 0 && num == 0)
		info->tmp = ft_strdup("");
	else
		info->tmp = ft_itoa(num);
	if (info->tmp == NULL)
		return (IS_ERROR);
	pre_pad_len = pre_pad_len_d(info, info->tmp, is_neg);
	if (put_padding(info, pre_pad_len, true))
		return (IS_ERROR);
	if (put_plus_minus_space(info, is_neg))
		return (IS_ERROR);
	if (put_zero_pad(info, pre_pad_len))
		return (IS_ERROR);
	if (put_precision_zero(info, ft_strlen(info->tmp), is_neg))
		return (IS_ERROR);
	if (printf_write(info->tmp + is_neg, ft_strlen(info->tmp) - is_neg, info))
		return (IS_ERROR);
	if (put_padding(info, pre_pad_len, false))
		return (IS_ERROR);
	return (0);
}
