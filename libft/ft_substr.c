/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:53:01 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/16 16:30:53 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	length;

	length = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len < (size_t)length)
		length = len;
	i = 0;
	res = (char *)malloc(sizeof(char) * (length + 1));
	if (!res)
		return (NULL);
	while (len > 0 && s[start])
	{
		res[i] = s[start];
		i++;
		start++;
		len--;
	}
	res[i] = '\0';
	return (res);
}
