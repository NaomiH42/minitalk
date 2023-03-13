/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:52:06 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/13 16:52:07 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	int		i;
	int		cpsize;

	i = 0;
	if ((int)size < 0)
		size = ft_strlen(src) + ft_strlen(dst) + 1;
	cpsize = size - ft_strlen(dst) - 1;
	len = ft_strlen(dst) + ft_strlen(src);
	if (size == 0)
		return (size + ft_strlen(src));
	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	while (*dst)
		dst++;
	while (src[i] && i < cpsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
