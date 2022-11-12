/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:22:17 by asasada           #+#    #+#             */
/*   Updated: 2022/05/07 21:23:02 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "info_controls.h"

void	read_flags(t_info *info, const char *fmt, size_t *fmt_i)
{
	while (true)
	{
		if (fmt[*fmt_i] == '-')
			info->left_align = true;
		else if (fmt[*fmt_i] == ' ')
			info->space = true;
		else if (fmt[*fmt_i] == '0')
			info->zero_pad = true;
		else if (fmt[*fmt_i] == '+')
			info->plus = true;
		else if (fmt[*fmt_i] == '#')
			info->hash = true;
		else
			break ;
		(*fmt_i)++;
	}
}

void	apply_flag_rules(t_info *info)
{
	if (info->left_align == true && info->zero_pad == true)
		info->zero_pad = false;
	if (info->preci_flag == true && info->zero_pad == true)
		info->zero_pad = false;
	if (info->plus == true && info->space == true)
		info->space = false;
}

void	assign_initial_info_values(t_info *info)
{
	info->tmp = NULL;
	info->print_len = 0;
	info->preci_flag = false;
	info->preci = 0;
	info->left_align = false;
	info->space = false;
	info->zero_pad = false;
	info->plus = false;
	info->hash = false;
	info->width = 0;
}

void	reset_flags(t_info *info)
{
	info->preci_flag = false;
	info->preci = 0;
	info->left_align = false;
	info->space = false;
	info->zero_pad = false;
	info->plus = false;
	info->hash = false;
	info->width = 0;
}
