/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:31:40 by asasada           #+#    #+#             */
/*   Updated: 2022/05/07 22:38:34 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"
#include "info_controls.h"
#include "read_precision.h"
#include "libft.h"

#define IS_ERROR -1

int	printf_write(const char *str, int n, t_info *info);
int	put_c(t_info *info, char c);
int	put_s(t_info *info, char *str);
int	put_p(t_info *info, unsigned long long ptr);
int	put_di(t_info *info, int num);
int	put_u(t_info *info, unsigned int num);
int	put_xx(t_info *info, unsigned int num, bool is_captical);
int	put_percentage(t_info *info);

int	read_specifiers_and_write(t_info *info, const char *fmt, va_list *ap)
{
	int	ret;

	if (*fmt == 'c')
		ret = put_c(info, va_arg(*ap, int));
	else if (*fmt == 's')
		ret = put_s(info, va_arg(*ap, char *));
	else if (*fmt == 'p')
		ret = put_p(info, (unsigned long long)va_arg(*ap, void *));
	else if (*fmt == 'd' || *fmt == 'i')
		ret = put_di(info, va_arg(*ap, int));
	else if (*fmt == 'u')
		ret = put_u(info, va_arg(*ap, unsigned int));
	else if (*fmt == 'x')
		ret = put_xx(info, va_arg(*ap, unsigned int), false);
	else if (*fmt == 'X')
		ret = put_xx(info, va_arg(*ap, unsigned int), true);
	else if (*fmt == '%')
		ret = put_percentage(info);
	else
		ret = IS_ERROR;
	return (ret);
}

static int	format_string(t_info *info, const char *fmt, va_list *ap)
{
	size_t	fmt_i;
	int		ret;

	fmt_i = 0;
	read_flags(info, fmt, &fmt_i);
	if (read_width(info, fmt, &fmt_i, ap) == IS_ERROR)
		return (IS_ERROR);
	if (read_precision(info, fmt, &fmt_i, ap) == IS_ERROR)
		return (IS_ERROR);
	apply_flag_rules(info);
	ret = read_specifiers_and_write(info, fmt + fmt_i, ap);
	free(info->tmp);
	info->tmp = NULL;
	if (ret == IS_ERROR)
		return (IS_ERROR);
	else
		fmt_i++;
	reset_flags(info);
	return (fmt_i);
}

static int	write_til_percentage(t_info *info, const char *fmt)
{
	char	*ptr_percentage;
	char	*ptr_nullchar;
	size_t	print_len;

	ptr_percentage = ft_strchr(fmt, '%');
	ptr_nullchar = ft_strchr(fmt, '\0');
	if (ptr_percentage)
		print_len = ptr_percentage - fmt;
	else
		print_len = ptr_nullchar - fmt;
	if (printf_write(fmt, print_len, info) == IS_ERROR)
		return (IS_ERROR);
	return (print_len);
}

static int	printf_ret(int ret, int print_len)
{
	if (ret == -1)
		return (-1);
	else
		return (print_len);
}

int	ft_printf(const char *fmt, ...)
{
	size_t	i;
	va_list	ap;
	int		ret;
	t_info	info;

	va_start(ap, fmt);
	assign_initial_info_values(&info);
	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			ret = format_string(&info, &fmt[i], &ap);
		}
		else
			ret = write_til_percentage(&info, &fmt[i]);
		if (ret == IS_ERROR)
			break ;
		else
			i += ret;
	}
	va_end(ap);
	return (printf_ret(ret, info.print_len));
}
