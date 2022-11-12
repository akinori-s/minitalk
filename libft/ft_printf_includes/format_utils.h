/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_specifiers_and_write.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:30:07 by asasada           #+#    #+#             */
/*   Updated: 2022/05/07 15:09:49 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_UTILS_H
# define FORMAT_UTILS_H

# include "info_controls.h"
# define IS_ERROR -1

int		printf_write(const char *str, size_t n, t_info *info);
char	*make_padding(size_t len, char c);
int		put_padding(t_info *info, int pre_pad_len, bool is_prefix);
int		put_zero_pad(t_info *info, int pre_pad_len);
int		put_precision_zero(t_info *info, int strlen, bool is_neg);

#endif
