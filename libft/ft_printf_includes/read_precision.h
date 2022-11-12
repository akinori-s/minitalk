/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_precision.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:29:30 by asasada           #+#    #+#             */
/*   Updated: 2022/05/07 14:59:02 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_PRECISION_H
# define READ_PRECISION_H

int	read_width(t_info *info, const char *fmt, size_t *fmt_i, va_list *ap);
int	read_precision(t_info *info, const char *fmt, size_t *fmt_i, va_list *ap);

#endif
