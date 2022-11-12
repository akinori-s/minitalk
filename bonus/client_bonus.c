/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:17:41 by asasada           #+#    #+#             */
/*   Updated: 2022/11/12 19:58:53 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

#define U_SECS 50
#define TRUE 1
#define FALSE 0

typedef struct s_ctl {
	volatile sig_atomic_t	can_send;
	int						s_pid;
}	t_ctl;

static t_ctl	g_ctl;

static void	send_message(pid_t pid, char *message)
{
	int	i;

	g_ctl.can_send = TRUE;
	while (*message != '\0')
	{
		i = 0;
		while (i < 8)
		{
			while (g_ctl.can_send == FALSE)
				pause();
			g_ctl.can_send = FALSE;
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

static void	handler(int sig, siginfo_t *siginfo, void *ucontext)
{
	(void)sig;
	(void)ucontext;
	if (siginfo->si_pid == g_ctl.s_pid || siginfo->si_pid == 0)
		g_ctl.can_send = TRUE;
}

static int	parse_pid(char *str)
{
	if (str == NULL || *str == '\0')
		return (-1);
	return (ft_atoi(str));
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Invalid usage.\n");
		return (-1);
	}
	g_ctl.s_pid = parse_pid(argv[1]);
	if (g_ctl.s_pid < 100 || g_ctl.s_pid > 99998)
	{
		ft_printf("Invalid pid.\n");
		return (-1);
	}
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
	{
		ft_printf("Sigaction error.\n");
		exit(-1);
	}
	if (*argv[2])
		send_message(g_ctl.s_pid, argv[2]);
	return (0);
}
