/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:24:52 by asasada           #+#    #+#             */
/*   Updated: 2022/11/06 13:24:52 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

char	*get_next_line(int fd);

size_t	gnl_strlen(const char *str);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(const char *src);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_substr(char const *s, size_t start, size_t len);

#endif