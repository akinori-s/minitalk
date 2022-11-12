/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_xxpercent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:38:34 by asasada           #+#    #+#             */
/*   Updated: 2022/09/05 21:38:34 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_controls.h"
#include "format_utils.h"
#include "libft.h"

void	set_default_uxx_preci(t_info *info);
char	*uint_to_str(unsigned int n, int base);

int	put_alternate_form(t_info *info, unsigned int num, bool is_captical)
{
	int	ret;

	if (info->preci_flag && info->preci == 0 && num == 0)
		return (0);
	if (info->hash == false || num == 0)
		return (0);
	if (is_captical)
		ret = printf_write("0X", 2, info);
	else
		ret = printf_write("0x", 2, info);
	return (ret);
}

void	xx_convert_case(char *str, bool is_capital)
{
	if (is_capital)
	{
		while (*str != '\0')
		{
			*str = ft_toupper(*str);
			str++;
		}
	}
}

int	pre_pad_len_xx(t_info *info, unsigned int num)
{
	int	pre_pad_len;

	pre_pad_len = ft_strlen(info->tmp);
	if (info->preci_flag == true && info->preci > pre_pad_len)
		pre_pad_len = info->preci;
	if (info->hash == true && num != 0)
		pre_pad_len += 2;
	if (info->preci_flag == true && info->preci == 0 && num == 0)
		pre_pad_len = 0;
	return (pre_pad_len);
}

int	put_xx(t_info *info, unsigned int num, bool is_captical)
{
	int	pre_pad_len;

	set_default_uxx_preci(info);
	if (info->preci_flag == true && info->preci == 0 && num == 0)
		info->tmp = ft_strdup("");
	else
		info->tmp = uint_to_str(num, 16);
	if (info->tmp == NULL)
		return (IS_ERROR);
	pre_pad_len = pre_pad_len_xx(info, num);
	xx_convert_case(info->tmp, is_captical);
	if (put_padding(info, pre_pad_len, true))
		return (IS_ERROR);
	if (put_alternate_form(info, num, is_captical))
		return (IS_ERROR);
	if (put_zero_pad(info, pre_pad_len))
		return (IS_ERROR);
	if (put_precision_zero(info, ft_strlen(info->tmp), false))
		return (IS_ERROR);
	if (printf_write(info->tmp, ft_strlen(info->tmp), info))
		return (IS_ERROR);
	if (put_padding(info, pre_pad_len, false))
		return (IS_ERROR);
	return (0);
}

int	put_percentage(t_info *info)
{
	int	ret;

	ret = printf_write("%", 1, info);
	return (ret);
}
