/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:17:41 by asasada           #+#    #+#             */
/*   Updated: 2022/11/12 20:00:27 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

#define U_SECS 100

static void	send_message(pid_t pid, char *message)
{
	int	i;

	while (*message != '\0')
	{
		i = 0;
		while (i < 8)
		{
			usleep(U_SECS);
			if ((*message >> (7 - i)) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
		}
		message++;
	}
}

static int	parse_pid(char *str)
{
	if (str == NULL || *str == '\0')
		return (-1);
	return (ft_atoi(str));
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Invalid usage.\n");
		return (-1);
	}
	pid = parse_pid(argv[1]);
	if (pid < 100 || pid > 99998)
	{
		ft_printf("Invalid pid.\n");
		return (-1);
	}
	if (*argv[2])
		send_message(pid, argv[2]);
	return (0);
}
