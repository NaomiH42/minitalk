/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:52:54 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/13 16:52:55 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	len;
	size_t	j;
	char	*temp;

	len = ft_strlen(s1);
	i = 0;
	start = 0;
	j = 0;
	while (in_set(s1[i], set))
		i++;
	start = i;
	while (in_set(s1[len - 1], set))
		len--;
	if (start >= len)
		return (ft_strdup(""));
	temp = (char *)malloc(sizeof(char) * (len - start + 1));
	if (!temp)
		return (NULL);
	while (start < len)
		temp[j++] = s1[start++];
	temp[j] = '\0';
	return (temp);
}
