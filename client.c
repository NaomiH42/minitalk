/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:39:36 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/20 23:22:30 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>


void    handle_sigusr1(int sig)
{
    printf("aaa");
}

int main(int argc, char **argv)
{
    int server_pid;
    struct sigaction sa;
    
    sa.sa_handler = handle_sigusr1;
    sigaction(SIGUSR1, &sa, NULL);
    server_pid = atoi(argv[1]);
    kill(server_pid, SIGUSR1);
}


