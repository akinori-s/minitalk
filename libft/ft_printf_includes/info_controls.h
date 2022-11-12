/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_controls.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:30:13 by asasada           #+#    #+#             */
/*   Updated: 2022/04/24 22:30:13 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_CONTROLS_H
# define INFO_CONTROLS_H
# include <stdbool.h>
# include <stddef.h>

typedef struct s_info
{
	size_t	print_len;
	char	*tmp;
	bool	preci_flag;
	int		preci;
	bool	left_align;
	bool	space;
	bool	zero_pad;
	bool	plus;
	bool	hash;
	int		width;
}	t_info;

void	read_flags(t_info *info, const char *fmt, size_t *fmt_i);
void	apply_flag_rules(t_info *info);
void	assign_initial_info_values(t_info *info);
void	reset_flags(t_info *info);

#endif
