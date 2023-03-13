/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:52:29 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/13 16:52:30 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	l;

	l = 1;
	if (n == 0)
		return (0);
	while (s1 && s2 && (*(unsigned char *)s1 == *(unsigned char *)s2) && l != n)
	{
		l++;
		s1++;
		s2++;
	}
	i = *(unsigned char *)s1 - *(unsigned char *)s2;
	return (i);
}
