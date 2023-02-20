/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:39:30 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/20 23:19:15 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    handler(int signum)
{
    if (signum == SIGUSR1)
    {
        printf("aaa");
    }
}

int main(void)
{
    int pid1;
    char    *pid;
    
    pid1 = getpid();
    pid = ft_itoa(pid1);
    write(1, pid, strlen(pid));
    signal(SIGUSR1, handler);
    pause();
}
