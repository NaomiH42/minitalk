/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:49:39 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/16 15:51:30 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n == 2147483647)
		return (10);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static size_t	res_fill(int n, char *res, size_t i)
{
	if (n == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
		n = 147483648;
		i += 2;
	}
	if (n < 0)
	{
		res[i] = '-';
		n *= -1;
		i++;
	}
	if (n >= 10)
	{
		i = res_fill(n / 10, res, i);
		i = res_fill(n % 10, res, i);
	}
	if (n < 10)
	{
		res[i] = n + '0';
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc(sizeof(*res) * (get_len(n) + 1));
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	else
		res_fill(n, res, i);
	res[get_len(n)] = '\0';
	return (res);
}
