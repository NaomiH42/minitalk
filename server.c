/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:39:30 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/21 12:38:44 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	bytes;
	static int	client_pid;
	static char	c;

	(void)context;
	client_pid = info->si_pid;
	if (signum == SIGUSR1)
	{
		c |= (0x01 << bytes);
		bytes++;
	}
	else if (signum == SIGUSR2)
		bytes++;
	if (bytes == 8)
	{
		if (c == 0)
			kill(client_pid, SIGUSR2);
		else
			write(1, &c, 1);
		c = 0;
		bytes = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid1;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	(void)argv;
	(void)argc;
	pid1 = getpid();
	sigemptyset(&sa.sa_mask);
	ft_putnbr_fd(pid1, 1);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
