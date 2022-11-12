/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:15:41 by asasada           #+#    #+#             */
/*   Updated: 2022/11/06 13:15:41 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static void	free_error(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

static int	read_line(int fd, char	*buf, char **str)
{
	ssize_t	buf_len;
	char	*tmp;

	if (!*str || !gnl_strchr(*str, '\n'))
	{
		buf_len = read(fd, buf, BUFFER_SIZE);
		if (buf_len == 0 && gnl_strlen(*str) == 0)
			return (1);
		while (buf_len > 0)
		{
			buf[buf_len] = '\0';
			if (!*str)
				*str = gnl_strdup(buf);
			else
			{
				tmp = *str;
				*str = gnl_strjoin(*str, buf);
				free(tmp);
			}
			if (gnl_strchr(buf, '\n'))
				break ;
			buf_len = read(fd, buf, BUFFER_SIZE);
		}
	}
	return (0);
}

static char	*prep_next_line(char **str)
{
	char	*res;
	char	*nl_ptr;
	char	*tmp;

	nl_ptr = gnl_strchr(*str, '\n');
	if (!nl_ptr)
	{
		res = gnl_strdup(*str);
		free(*str);
		*str = NULL;
		return (res);
	}
	res = gnl_substr(*str, 0, nl_ptr - *str + 1);
	tmp = *str;
	*str = gnl_strdup(nl_ptr + 1);
	free(tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*res;
	static char	*str[OPEN_MAX];
	int			eof;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (read(fd, buf, 0) == -1 || BUFFER_SIZE < 1 || fd < 0)
	{
		free_error(&str[fd]);
		free(buf);
		return (NULL);
	}
	buf[BUFFER_SIZE] = '\0';
	eof = read_line(fd, buf, &str[fd]);
	res = prep_next_line(&str[fd]);
	free(buf);
	if (eof == 1)
	{
		free(res);
		res = NULL;
	}
	return (res);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*ptr;
	int		stat;
	char	buf[10];

	// printf("%d\n", BUFFER_SIZE);
	fd1 = open("../tests/1.txt", O_RDONLY);
	fd2 = open("../tests/2.txt", O_RDONLY);
	fd3 = open("../tests/3.txt", O_RDONLY);

	// write(2, ptr, gnl_strlen(ptr));
	ptr = get_next_line(fd1);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd2);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd3);
	printf("%s", ptr);
	free(ptr);

	ptr = get_next_line(fd1);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd2);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd3);
	printf("%s", ptr);
	free(ptr);

	ptr = get_next_line(fd1);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd2);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd3);
	printf("%s", ptr);
	free(ptr);

	ptr = get_next_line(fd1);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd2);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd3);
	printf("%s", ptr);
	free(ptr);

	ptr = get_next_line(fd1);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd2);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd3);
	printf("%s", ptr);
	free(ptr);

	stat = read(fd1, &buf, 1);
	printf("stat: %d\n", stat);

	stat = read(fd2, &buf, 1);
	printf("stat: %d\n", stat);

	stat = read(fd3, &buf, 1);
	printf("stat: %d\n", stat);
	// ptr = get_next_line(fd1);
	// printf("%s", ptr);
	// free(ptr);
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s\n", get_next_line(fd1));
	// printf("%s\n", get_next_line(fd1));
	// printf("%s\n", get_next_line(fd1));
	// printf("%s\n", get_next_line(1));

	close(fd1);
	close(fd2);
	close(fd3);

	ptr = get_next_line(0);
	printf("%s", ptr);
	free(ptr);

	return (0);
}
*/