/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:52:36 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/13 16:52:36 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_needle(const char *haystack, const char *needle, size_t i)
{
	size_t	j;

	j = 0;
	while (needle[j])
	{
		if (haystack[i] != needle[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len && (ft_strlen(little) <= (len - i)))
	{
		if (is_needle(big, little, i))
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
