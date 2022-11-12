/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:35:13 by asasada           #+#    #+#             */
/*   Updated: 2022/09/05 21:35:13 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_controls.h"
#include "format_utils.h"
#include "libft.h"

int	pre_pad_len_c(void)
{
	return (1);
}

int	put_c(t_info *info, char c)
{
	int		pre_pad_len;

	pre_pad_len = pre_pad_len_c();
	if (put_padding(info, pre_pad_len, true))
		return (IS_ERROR);
	if (printf_write(&c, 1, info))
		return (IS_ERROR);
	if (put_padding(info, pre_pad_len, false))
		return (IS_ERROR);
	return (0);
}

size_t	pre_pad_len_s(t_info *info, char *str)
{
	size_t	strlen;

	if (str == NULL)
		strlen = ft_strlen("(null)");
	else
		strlen = ft_strlen(str);
	if (info->preci_flag == true && (size_t)info->preci < strlen)
		return (info->preci);
	else
		return (strlen);
}

int	put_s(t_info *info, char *str)
{
	int	pre_pad_len;

	pre_pad_len = pre_pad_len_s(info, str);
	if (put_padding(info, pre_pad_len, true))
		return (IS_ERROR);
	if (str == NULL)
	{
		if (printf_write("(null)", pre_pad_len, info))
			return (IS_ERROR);
	}
	else
	{
		if (printf_write(str, pre_pad_len, info))
			return (IS_ERROR);
	}
	if (put_padding(info, pre_pad_len, false))
		return (IS_ERROR);
	return (0);
}
