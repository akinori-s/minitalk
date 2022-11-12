/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:17:39 by asasada           #+#    #+#             */
/*   Updated: 2022/11/12 19:35:20 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

#define U_SECS 50

static volatile sig_atomic_t	g_c_pid;

static void	handler(int sig, siginfo_t *siginfo, void *ucontext)
{
	static char	c = 0;
	static int	len = 0;

	(void)ucontext;
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
	if (siginfo->si_pid != 0)
	{
		g_c_pid = siginfo->si_pid;
		kill(g_c_pid, SIGUSR1);
	}
	else
		kill(g_c_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
		exit(-1);
	if (sigaction(SIGUSR2, &sa, NULL) < 0)
		exit(-1);
	while (1)
		pause();
	return (0);
}
