/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:39:36 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/21 13:05:30 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>

void	the_thing(int server_pid, char c)
{
	int	bytes;

	bytes = 0;
	while (bytes < 8)
	{
		if (c & (0x01 << bytes))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(721);
		bytes++;
	}
}

void	bit_receieved(int signum)
{
	if (signum == SIGUSR2)
		write(1, "RECIEVED\n", 10);
	signal(SIGUSR1, bit_receieved);
	signal(SIGUSR2, bit_receieved);
}

int	main(int argc, char **argv)
{
	int	i;
	int	server_pid;

	if (argc != 3)
	{
		write(1, "Incorrect number of arguments\n", 30);
		return (0);
	}
	argc++;
	i = 0;
	server_pid = atoi(argv[1]);
	signal(SIGUSR1, bit_receieved);
	signal(SIGUSR2, bit_receieved);
	while (argv[2][i] != '\0')
	{
		the_thing(server_pid, argv[2][i]);
		i++;
	}
	the_thing(server_pid, 0);
}
