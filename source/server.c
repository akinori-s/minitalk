/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:17:39 by asasada           #+#    #+#             */
/*   Updated: 2022/11/12 17:36:55 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static void	handler(int sig)
{
	static char	c = 0;
	static int	len = 0;

	c <<= 1;
	len += 1;
	if (sig == SIGUSR1)
		c += 1;
	if (len == 8)
	{
		write(1, &c, 1);
		c = 0;
		len = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
		exit(-1);
	if (sigaction(SIGUSR2, &sa, NULL) < 0)
		exit(-1);
	while (1)
		pause();
	return (0);
}
